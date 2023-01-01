#pragma once
#include "string"

using namespace std;

class Helper {
	string EXIT = "EXIT";
	string CORRECT = "GGGGG";
public:
	bool shouldExit(string input);
	bool wordCorrect(string input);
	bool invalidInput(string input);
	void convertToUpper(string& input);
};
