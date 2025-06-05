#include "Hangman.h"  
using namespace std;  


size_t HangmanGame::gameTries = 0;  

void HangmanGame::updateHangmanDisplay()
{	// Add parts based on wrongGuesses
	if (attemptsLeft > 6) hangman[2][2] = 'O';         // Head
	else if (attemptsLeft > 5) hangman[3][2] = '|';         // Body
	else if (attemptsLeft > 4) hangman[3][1] = '/';         // Left arm
	else if (attemptsLeft > 3) hangman[3][3] = '\\';        // Right arm
	else if (attemptsLeft > 2) hangman[4][1] = '/';         // Left leg
	else if (attemptsLeft > 1) hangman[4][3] = '\\';        // Right leg
}

void HangmanGame::resetHangmanDisplay()
{
	hangman[2][2] = ' '; // Head
	hangman[3][2] = ' '; // Body
	hangman[3][1] = ' '; // Left arm
	hangman[3][3] = ' '; // Right arm
	hangman[4][1] = ' '; // Left leg
	hangman[4][3] = ' '; // Right leg

}

HangmanGame::HangmanGame(WordsList& word)
{  
   currentWord = word.getRandomWord();  
   attemptsLeft = 6;  
   guessedLetters = "";  
   hangman = {
		"  +---+",
		"  |   |",
		"      |",
		"      |",
		"      |",
		"      |",
		"========="
   };
}  

void HangmanGame::startGame()  
{
	cout << "Welcome to the Hangman Game!" << endl;
	cout << "You will have to guess the word by suggesting letters." << endl;
	cout << "You have a six attempts." << endl;
	cout << "Let's start timer!" << endl;  
	startTime = std::chrono::steady_clock::now(); 
	gameTries++;
}

void HangmanGame::gameOver()
{
	if (isWordGuessed()) {
		cout << "Congratulations! You guessed the word: " << currentWord << endl;
	}
	else {
	cout << "Game Over!" << endl
		 << "You ran out of attempts!" << endl
		 << "The word was: " << currentWord << endl
		 << "Your guesses was: " << guessedLetters << endl;
	}
	displayStatistics();
}

void HangmanGame::resetGame(WordsList& word)
{
	currentWord = word.getRandomWord();
	attemptsLeft = 6;
	guessedLetters.clear();
	startTime = std::chrono::steady_clock::now();
	resetHangmanDisplay();
	gameTries++;
}

void HangmanGame::guessLetter(char letter)
{
	if (guessedLetters.find(letter) != string::npos) {
		cout << "You already guessed the letter: " << letter << endl;
		return;
	}
	guessedLetters += letter;
	if (currentWord.find(letter) == string::npos) {
		attemptsLeft--;
		cout << "Wrong guess! Attempts left: " << attemptsLeft << endl;
		updateHangmanDisplay();
		displayHangman();
	}
	else {
		cout << "Good guess!" << endl;
	}
}

bool HangmanGame::isGameOver() const
{
	if (attemptsLeft <= 0) {
		return true;
	}
	return false;
}

bool HangmanGame::isWordGuessed() const
{
	for (auto it = currentWord.begin(); it != currentWord.end(); ++it) {
		char c = *it;
		if (guessedLetters.find(c) == string::npos) {
			return false;
		}
	}
	return true;
}

void HangmanGame::displayStatistics() const
{    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
	cout << "Game time: " << duration << " seconds." << endl
		<< "Attempts: " << gameTries << endl;
}

void HangmanGame::displayHangman()
{
	for (auto it = hangman.begin(); it != hangman.end(); ++it) {
		cout << *it << endl;
	}

}

void HangmanGame::displayCurrentState() const
{
	cout << "Current word: ";
	for (auto it = currentWord.begin(); it != currentWord.end(); ++it) {
		char c = *it;
		if (guessedLetters.find(c) != string::npos) {
			cout << c << " ";
		}
		else {
			cout << "_ ";
		}
	}
	cout << endl;
}