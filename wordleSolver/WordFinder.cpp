#include "WordFinder.h"
#include "fstream"
#include <iostream>

using namespace std;

WordFinder::WordFinder() {
	lastIncorrectWord = "steal";
	ifstream file(FILE);
	if (file.bad()) {
		cerr << "Unable to open file" << endl;
		exit(EXIT_FAILURE);
	}
	string cur;
	while (file >> cur) {
		WORDS.push_back(cur);
	}
}

string WordFinder::predict(string input) {
	filter(input);
	lastIncorrectWord = WORDS.front();
	return WORDS.front();
}

void WordFinder::filter(string input) {
	list<string>::const_iterator itr = WORDS.begin();
	while (itr != WORDS.end()) {
		if (!isPossibleWord(*itr, input)) {
			itr = WORDS.erase(itr);
		} else {
			++itr;
		}
	}
}

bool WordFinder::isPossibleWord(string word, string input) {
	bool usedChar[5] = {false, false, false, false, false};
	for (int i = 0; i < 5; i++) {
		char c = input[i];
		char letter = lastIncorrectWord[i];
		bool foundLetter = false;
		switch (c) {
		case 'G':
			if (word[i] != lastIncorrectWord[i]) {
				// cout << "Debug G " + word << endl;
				return false;
			}
			usedChar[i] = true;
			break;
		case 'Y':
			for (int j = 0; j < 5; j++) {
				if (word[j] == letter && usedChar[j] == false && i != j) {
					usedChar[j] = true;
					foundLetter = true;
					break;
				}
			}
			if (!foundLetter) {
				// cout << "Debug Y " + word << endl;
				return false;
			}
			break;
		default:
			for (int j = 0; j < 5; j++) {
				if (word[j] == letter && !usedChar[j]) {
					// cout << "Debug - " + word << endl;
					return false;
				}
			}
			break;
		}
	}
	return true;
}