﻿#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <random>
#include <nlohmann/json.hpp>
#include "Decript.h"
using json = nlohmann::json;

/*
	WordsList
• is only responsible for storing and managing the list of words 
• Methods: loading, adding, obtaining a random word.
*/
class WordsList {
	private:
		std::vector<std::string> words;
		std::string filePath;
		short encrypt = 3;
public:
	explicit WordsList(const std::string& filePath) : filePath(filePath) {
			loadWordsFromFile();
		}
	WordsList(const std::string& filePath, short x) : filePath(filePath), encrypt (x){
		loadWordsFromFile();
	}

	void loadWordsFromFile();
	const std::vector<std::string>& getWords() const {return words;}

	std::string getRandomWord() const;

}; 