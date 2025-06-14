﻿#pragma once

#include <string>
#include <vector>
/*
Decript
is responsible for encryption/decryption of words.


*/
struct Decript {
public:

    static std::string caesarDecrypt(const std::string& word, int shift = 3);
    static std::vector<std::string> decryptWords(const std::vector<std::string>& words, int shift = 3);
};