#pragma once
#include "string"

using namespace std;

class Helper {
	string EXIT = "exit";
	string CORRECT = "GGGGG";
public:
	bool shouldExit(string input);
	bool wordCorrect(string input);
};
