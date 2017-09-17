// Team Polk Members: Vladislav Ignatov, Leonard Holloman, Walter Soulliere, Timothy Jones
#include <iostream>
#include <string.h>
using namespace std;

// Displays student data, all of the class or just one student. READ ONLY. INDEPENDENT FUNCTION
void DISPLAY() {
	cout << "Display data\n";
}

// Write student data or change it
void WRITE() {
	DISPLAY();
	cout << "Write data\n";
}

// Adds student to the database
void ADD() {
	cout << "ADD STUDENT\n";
}

// Delete student from database
void DELETE() {
	cout << "DELETE STUDENT\n";
}

// Saerch for a student
void SEARCH() {
	DISPLAY();
	cout << "SEARCH for a Student\n";
}

// Saerch for a student
void UPDATE() {
	DISPLAY();
	cout << "UPDATE a Students Info\n";
}

int main() {

	int choice = 0;

	while (1) {
		cout << "Welcome to USF Class-Roll System\n";
		cout << "1: READ Student Data\n";
		cout << "2: WRITE Student Data\n";
		cout << "3: ADD Student\n";
		cout << "4: DELETE Student\n";
		cout << "5: SEARCH Student\n";
		cout << "6: UPDATE Student\n";
		cout << "7: EXIT\n";
		cout << "Enter in a number (1-7): ";

		cin >> choice;

		switch (choice)
		{
		case(1):
			DISPLAY();
			break;
		case(2):
			WRITE();
			break;
		case(3):
			ADD();
			break;
		case(4):
			DELETE();
			break;
		case(5):
			SEARCH();
			break;
		case(6):
			UPDATE();
			break;
		case(7)://EXIT
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
