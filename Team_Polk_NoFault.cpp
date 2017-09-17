// Team Polk Members: Vladislav Ignatov, Leonard Holloman, Walter Soulliere, Timothy Jones
#include <iostream>
using namespace std;

int main() {

	int choice = 0;

	while (1) {
		cout << "Welcome to USF Class-Roll System\n";
		cout << "1: READ\n";
		cout << "2: ADD\n";
		cout << "3: DELETE\n";
		cout << "4: SEARCH\n";
		cout << "Enter in a number (1-4): ";

		cin >> choice;

		switch (choice)
		{
		case(1):
			cout << "Picked 1 \n";
			break;
		case(2):
			cout << "Picked 2 \n";
			break;
		case(3):
			cout << "Picked 3 \n";
			break;
		case(4):
			cout << "Picked 4 \n";
			break;
		default:
			break;
		}
	}

	return 0;
}
