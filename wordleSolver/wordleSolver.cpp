#include <iostream>
#include <string>
#include "Helper.h"

using namespace std;

int main() {
	Helper helper;
	string input;

	cout << "Insert guess: ";
	cin >> input;
	while (true) {
		if (helper.shouldExit(input)) {
			break;
		}
		cout << "Insert letter correctness. Use - for incorrect, G for green, Y for yellow: ";
		cin >> input;

		if (helper.wordCorrect(input)) {
			cout << "Congrats!";
			break;
		}
	}

	return 0;
}