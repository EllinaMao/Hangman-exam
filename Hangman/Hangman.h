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
	//Word, list of guessed letters, attempts left, start time
	std::string currentWord;
	std::string guessedLetters;
	short attemptsLeft;
	std::chrono::time_point<std::chrono::steady_clock> startTime;

	// static variable how many tries player has in game
	static size_t gameTries;

	/// image of hangman
	std::vector<std::string> hangman;

	//Update state of display methods
	void updateHangmanDisplay();
	void resetHangmanDisplay();
protected:
	std::string getCurrentWord() const { return currentWord; }
public:
	explicit HangmanGame(WordsList& word);

	//Game methods
	void startGame();
	void gameOver()const;
	void resetGame(WordsList& word);
	void guessLetter(char letter);

	//Check methods is game over or word guessed
	bool isGameOver() const;
	bool isWordGuessed() const;

	//Getters in case of need
	std::string getGuessedLetters() const { return guessedLetters; }
	int getAttemptsLeft() const { return attemptsLeft; }

	//Difficulty methods
	void OpenTwoLetters();

	//Display methods
	void displayCurrentState() const;
	void displayStatistics() const;
	void displayHangman() const;
	void displayGuessedLetters() const;
};
