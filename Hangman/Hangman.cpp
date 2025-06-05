#include "Hangman.h"

HangmanGame::HangmanGame(WordsList& word)
{
	currentWord = word.getRandomWord();
	attemptsLeft = 7;
	guessedLetters = "";
}
