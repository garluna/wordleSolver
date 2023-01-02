#pragma once
#include <list>
#include "string"

using namespace std;

class WordFinder {
	string FILE = "words.txt";
	list<string> WORDS;
	string lastIncorrectWord;
public:
	WordFinder();
	string predict(string input);
	void filter(string input);
	bool isPossibleWord(string word, string input);
};
