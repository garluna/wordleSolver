#include <iostream>
#include <string>
#include "Helper.h"
#include "WordFinder.h"

using namespace std;

int main() {
	Helper helper;
	WordFinder wordFinder;
	string input;
	string prediction;

	cout << "Make the first guess STEAL" << endl;
	while (true) {
		cout << "Insert letter correctness. Use - for incorrect, G for green, Y for yellow: ";
		cin >> input;
		helper.convertToUpper(input);

		if (helper.shouldExit(input)) {
			exit(EXIT_SUCCESS);
		}

		if (helper.wordCorrect(input)) {
			cout << "Congrats!" << endl;
			break;
		}

		if (helper.invalidInput(input)) {
			cerr << "Input was invalid. Try inserting again." << endl;
		}

		prediction = wordFinder.predict(input);
		cout << "Guess " + prediction << endl;
	}

	exit(EXIT_SUCCESS);
}