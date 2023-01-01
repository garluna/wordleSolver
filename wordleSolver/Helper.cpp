#include "Helper.h"
#include "string"

using namespace std;

bool Helper::shouldExit(string input) {
	return EXIT == input;
}

bool Helper::wordCorrect(string input) {
	return CORRECT == input;
}

bool Helper::invalidInput(string input) {
	if (input.size() != 5) {
		return true;
	}

	for (int i = 0; i < input.size(); i++) {
		char cur = input[i];
		if (!(cur == '-' || cur == 'G' || cur == 'Y')) {
			return true;
		}
	}

	return false;
}

void Helper::convertToUpper(string& input) {
	for (int i = 0; i < input.size(); i++) {
		char cur = input[i];
		input[i] = toupper(cur);
	}
}