#include "Decript.h"
using namespace std;

string Decript::caesarDecrypt(const string& word, int shift)
{
    string decrypted = word;

    for (auto it = decrypted.begin(); it != decrypted.end(); ++it) {
        if (isalpha(*it)) {
            char base = islower(*it) ? 'a' : 'A';
            *it = (*it - base - shift + 26) % 26 + base;
        }
    }
    return decrypted;
}

vector<string> Decript::decryptWords(const vector<string>& words, int shift)
{
    vector<string> decrypted;
    for (auto it = words.begin(); it != words.end(); ++it) {
        decrypted.push_back(caesarDecrypt(*it, shift));
    }
    return decrypted;
}