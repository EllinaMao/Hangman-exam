#include "WordsList.h"
using namespace std;

//
//void WordsList::loadWordsFromFile()
//{
//	ifstream file(filePath);
//
//	if (!file.is_open()) {
//		cerr << "Error opening file: " << filePath << endl;
//		return;
//	}
//	json j;
//	file >> j;
//	vector<string> encripred = j["words"].get<vector<string>>();
//	file.close();
//	
//	words = Decript::decryptWords(encripred, encrypt);
//}
//

std::string WordsList::getRandomWord() const  
{  
if (words.empty()) {  
	throw std::runtime_error("No words available in the list.");  
}  
random_device rd; 
mt19937 generator(rd());  
uniform_int_distribution<size_t> distribution(0, (words.size() - 1));

return words.at(distribution(generator));  
}
