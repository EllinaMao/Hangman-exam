#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <chrono>
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
	short attemptsLeft;
	std::chrono::time_point<std::chrono::steady_clock> startTime;

	static size_t gameTries;
	vector<string> hangman;

	void updateHangmanDisplay();
	void resetHangmanDisplay();
protected:
	std::string getCurrentWord() const { return currentWord; }
public:
	explicit HangmanGame(WordsList& word);
	void startGame();
	void gameOver();
	void resetGame(WordsList& word);
	void guessLetter(char letter);
	bool isGameOver() const;
	bool isWordGuessed() const;
	std::string getGuessedLetters() const { return guessedLetters; }
	int getAttemptsLeft() const { return attemptsLeft; }
	void displayCurrentState() const;
	void displayStatistics() const;

	void displayHangman();
};
