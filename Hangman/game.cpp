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
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

void drawHangman(int wrongGuesses) {
    // Base
    vector<string> hangman = {
        "  +---+",
        "  |   |",
        "      |",
        "      |",
        "      |",
        "      |",
        "========="
    };

    // Add parts based on wrongGuesses
    if (wrongGuesses > 0) hangman[2][2] = 'O';         // Head
    if (wrongGuesses > 1) hangman[3][2] = '|';         // Body
    if (wrongGuesses > 2) hangman[3][1] = '/';         // Left arm
    if (wrongGuesses > 3) hangman[3][3] = '\\';        // Right arm
    if (wrongGuesses > 4) hangman[4][1] = '/';         // Left leg
    if (wrongGuesses > 5) hangman[4][3] = '\\';        // Right leg

    for (auto it = hangman.begin(); it != hangman.end(); ++it) {
        cout << *it << endl;
    }
};


int main()
{

    string encryptedWords = "words.json";
	cout << "Welcome to the Hangman Game!" << endl;
	cout << "You will have to guess the word by suggesting letters." << endl;
	cout << "You have a limited number of attempts." << endl;
	cout << "Let's start!" << endl;

    
	// Here you would typically load the word list from a file, decrypt it, and start the game logic.





}