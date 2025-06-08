#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "InputIO.h"
//Interactive menu for Hangman game
int showMenu(const std::vector<std::string>& options, const std::string& prompt);