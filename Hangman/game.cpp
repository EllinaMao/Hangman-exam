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
//#include <nlohmann/json.hpp>
using namespace std;

//using json = nlohmann::json;

void drawHangman(int wrongGuesses) {
    // Base
    vector<string> hangman = {
        "  +---+",
        "      |",
        "      |",
        "      |",
        "      |",
        "      |",
        "========="
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