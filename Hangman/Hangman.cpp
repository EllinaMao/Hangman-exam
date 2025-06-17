#include "Hangman.h"  
using namespace std;  
//#define TEST


// Initialize the amount of game tries
size_t HangmanGame::gameTries = 0;  

// 
void HangmanGame::updateHangmanDisplay()
{	// Add parts based on wrongGuesses
	if (attemptsLeft == 5) hangman[2][2] = 'O';         // Head
	else if (attemptsLeft == 4) hangman[3][2] = '|';         // Body
	else if (attemptsLeft == 3) hangman[3][1] = '/';         // Left arm
	else if (attemptsLeft == 2) hangman[3][3] = '\\';        // Right arm
	else if (attemptsLeft == 1) hangman[4][1] = '/';         // Left leg
	else if (attemptsLeft == 0) hangman[4][3] = '\\';        // Right leg
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
   //base
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

//Welcome message and start timer 
void HangmanGame::startGame()  
{
	cout << "Welcome to the Hangman Game!" << endl;
	cout << "You will have to guess the word by suggesting letters." << endl;
	cout << "You have a six attempts." << endl;
	cout << "Let's start timer!" << endl;  
	startTime = std::chrono::steady_clock::now(); 
	gameTries++;
}

//Game over message
void HangmanGame::gameOver() const
{
	displayHangman();
	if (isWordGuessed()) {
		cout << "Congratulations! You guessed the word: " << currentWord << endl;
	}
	else {
		cout << "Game Over!" << endl
			<< "You ran out of attempts!" << endl;
	}
	displayStatistics();

}

// Reset the game with a new word and reset attempts and guessed letters
void HangmanGame::resetGame(WordsList& word)
{
	currentWord = word.getRandomWord();
	attemptsLeft = 6;
	guessedLetters.clear();
	startTime = std::chrono::steady_clock::now();
	resetHangmanDisplay();
	gameTries++;
}

// Guess a letter and call the display update if necessary
void HangmanGame::guessLetter(char letter)
{
	
	if (letter < 'A' || (letter > 'Z' && letter < 'a') || letter > 'z') {
		cout << "Please enter a valid English letter." << endl;
		return;
	}

	letter = tolower(letter); // Case insensitivity
	if (!isalpha(letter)) {
		cout << "Please enter a valid letter." << endl;
		return;
	}

	if (guessedLetters.find(letter) != string::npos) {
		cout << "You already guessed the letter: " << letter << endl;
		return;
	}
	guessedLetters += letter;
	if (currentWord.find(letter) == string::npos) {
		attemptsLeft--;
		cout << "Wrong guess! Letter " << letter << " doesn`t belong to this word.\nAttempts left: " << attemptsLeft << endl;
		updateHangmanDisplay();
	}
	else {
		cout << "Good guess!" << endl;
	}
}

// Check if the game is over either by running out of attempts or guessing the word
bool HangmanGame::isGameOver() const
{
	if (attemptsLeft <= 0) {
		return true;
	}
	return false;
}
// Check if the word is guessed by checking if all letters are in guessedLetters
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

// Display the statistics of the game including time taken, attempts made, and the word
void HangmanGame::displayStatistics() const
{    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
	cout << "Game time: " << duration << " seconds." << endl
		<< "Attempts: " << gameTries << endl
		<< "The word was: " << currentWord << endl;
	displayGuessedLetters();
	
	system("pause");
}

// Open a letter in the word based on the first occurrence of a vowel
void HangmanGame::OpenTwoLetters()
{
	try {
		if (currentWord.length() < 2) {
			cout << "The word is too short to open two letters." << endl;
			return;
		}

		// Откроем первую букву
		char firstChar = currentWord[0];
		guessedLetters += firstChar;

		// Найдём вторую отличную букву (с конца, если совпадает — ищем следующую отличную)
		size_t secondIndex = currentWord.length() - 1;
		while (secondIndex > 0 && currentWord[secondIndex] == firstChar) {
			--secondIndex;
		}
		char secondChar = currentWord[secondIndex];
		if (guessedLetters.find(secondChar) == std::string::npos) {
			guessedLetters += secondChar;
		}

		cout << "Two letters opened: " << firstChar << " and " << secondChar << endl;
		displayCurrentState();
	}
	catch (const std::exception& e) {
		cout << "An error occurred: " << e.what() << endl;
	}
}

// Display the hangman figure
void HangmanGame::displayHangman() const
{

	system("cls");
	for (auto it = hangman.begin(); it != hangman.end(); ++it) {
		cout << *it << endl;
	}
#ifdef TEST
	cout << currentWord << endl;
	
#endif
}

// Display the guessed letters
void HangmanGame::displayGuessedLetters() const
{
	cout << "Your guessed letters: ";

	for (auto it = guessedLetters.begin(); it != guessedLetters.end(); ++it) {
		cout << *it << ", ";
		if (it == guessedLetters.end() - 1) { // If it's the last letter, don't print comma
			cout << "\b\b "; // Backspace to remove the last comma and space
		}
	}
	cout << endl;

}

// Display the current state of the word and call metod with guessed letters from player
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

	displayGuessedLetters();
}

