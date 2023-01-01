#include "Helper.h"
#include "string"

using namespace std;

bool Helper::shouldExit(string input) {
	return EXIT == input;
}

bool Helper::wordCorrect(string input) {
	return CORRECT == input;
}