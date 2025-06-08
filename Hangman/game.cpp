// classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Четвертое задание
Создайте консольную версию игры «Виселица».

Правила игры можно посмотреть по этой ссылке.

Важно:

Слово выбирается компьютером из списка слов.
Список слов находится в файле в зашифрованном виде.
По завершении игры на экран выводится статистика игры:
Количество времени;
Количество попыток;
Искомое слово;
Буквы игрока.

*/

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <chrono>
#include <nlohmann/json.hpp>
#include "Hangman.h"
#include "WordsList.h"
#include "Decript.h"
#include "InputIO.h"
#include "Menu.h"

using namespace std;

using json = nlohmann::json;

int main()
{
    try {
        string encryptedWords = "words.json";
        WordsList wordsList(encryptedWords);
        HangmanGame game(wordsList);

        while (true) {
            game.startGame();

             //Menu for opening two letters
            vector<string> openOptions = { "Don't open letters", "Open two letters" };
            int openChoice = showMenu(openOptions, "Do you want to open two letters?");
            if (openChoice == 1) {
                game.OpenTwoLetters();
            }

            while (!game.isGameOver() && !game.isWordGuessed()) {
                game.displayHangman();
                game.displayCurrentState();
                cout << "Enter a letter: ";
                char letter = InputIO::GetCh();
                game.guessLetter(letter);
            }
            game.gameOver();

             //Menu for playing again
            vector<string> playAgainOptions = { "Play again", "Exit" };
            int playAgainChoice = showMenu(playAgainOptions, "Do you want to play again?");
            if (playAgainChoice == 1) {
                cout << "Thank you for playing!" << endl;
                break;
            }
            game.resetGame(wordsList);
        }
        return 0;
    }
    catch (const std::exception& e) {
        cout << "Error loading words: " << e.what() << endl;
        return 1;
    }
}