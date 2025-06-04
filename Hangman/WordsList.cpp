#include "WordsList.h"
using namespace std;


void WordsList::loadWordsFromFile()
{
	ifstream file(filePath);

	if (!file.is_open()) {
		cerr << "Error opening file: " << filePath << endl;
		return;
	}
	json j;
	file >> j;
	vector<string> encripred = j["words"].get<vector<string>>();
	file.close();
	
	words = Decript::decryptWords(encripred, encrypt);
}

