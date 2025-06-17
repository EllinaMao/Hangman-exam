// classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Создайте консольную версию игры «Виселица».
Важно:

Слово выбирается компьютером из списка слов.
Список слов находится в файле в зашифрованном виде.+
По завершении игры на экран выводится статистика игры:+
Количество времени;+
Количество попыток;+
Искомое слово;+
Буквы игрока.+

*/

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <chrono>
#include <thread> 
#include <nlohmann/json.hpp>

   
#include "Hangman.h"
#include "WordsList.h"
#include "Decript.h"
#include "Menu.h"
using namespace std;

using json = nlohmann::json;

int main()
{
    try {
		//Text file with encrypted words
        string encryptedWords = "words.json";
		//Load words from the encrypted file
        WordsList wordsList(encryptedWords);
		//Create a Hangman game instance with one loaded random word
        HangmanGame game(wordsList);

        while (true) {
			//Menu for starting the game
            game.startGame();

            //Menu for choosing the difficulty level
            vector<string> openOptions = { "Don't open letters", "Open two letters" };
            int openChoice = showMenu(openOptions, "Do you want to open two letters?");
            if (openChoice == 1) {
                game.OpenTwoLetters();
            }

			//Actual game loop
            while (!game.isGameOver() && !game.isWordGuessed()) {
				//Display the hangman state
                game.displayHangman();
				//displayng letters and word
                game.displayCurrentState();
                cout << "Enter a letter: ";
                char letter = InputIO::GetCh();
                game.guessLetter(letter);
                this_thread::sleep_for(chrono::seconds(1));

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
    catch (...) {
        cout << "Unknown error occurred." << endl;
        return 2;
    }
}