#include <iostream>
#include <string>
#include "Helper.h"

using namespace std;

int main() {
	Helper helper;
	string input;

	cout << "Make the first guess STEAL" << endl;
	while (true) {
		cout << "Insert letter correctness. Use - for incorrect, G for green, Y for yellow: ";
		cin >> input;
		helper.convertToUpper(input);

		if (helper.shouldExit(input)) {
			break;
		}

		if (helper.wordCorrect(input)) {
			cout << "Congrats!" << endl;
			break;
		}

		if (helper.invalidInput(input)) {
			cout << "Input was invalid. Try inserting again." << endl;
		}
	}

	return 0;
}