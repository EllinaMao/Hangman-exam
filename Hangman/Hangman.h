#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include "WordsList.h"

/*
HangmanGame
•	Управляет логикой игры: текущее слово, количество попыток, угаданные буквы (Single Responsibility).
•	Методы: startGame, guessLetter, isGameOver, isWordGuessed
*/

class HangmanGame {
private:
	std::string currentWord;
	std::string guessedLetters;
	int attemptsLeft;
public:
	explicit HangmanGame(WordsList& word);
