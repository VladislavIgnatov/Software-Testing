// Team Polk Members: Vladislav Ignatov, Leonard Holloman, Walter Soulliere, Timothy Jones
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

// Displays student data, all of the class or just one student. READ ONLY. INDEPENDENT FUNCTION
void DISPLAY() {
	cout << "Display data" << endl;

	string line;
	ifstream db ("database.txt");

	if (db.is_open()) {
		while (getline(db, line))
		{
			cout << line << endl;
		}
		db.close();
	}
	else {
		cout << "File can not open." << endl;
	}
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
	
	// file decleration
	ofstream outfile;

	outfile.open("database.txt");

	// Populating the database
	outfile << "Rick Sanchaz, u01234567, regularrick@gmail.com, 100, 110, 120" << endl;
	outfile << "Morty Smith, u76543210, morty@gmail.com, 60, 75, 69" << endl;
	outfile << "Summer Smith, u88965238, summer@gmail.com, 85, 100, 90" << endl;
	outfile << "Walter White, u96571368, hizenburg@gmail.com, 100, 110, 120" << endl;
	outfile << "Jesse Pinkman, u79269858, pinkman@gmail.com, 30, 50, 20" << endl;

	outfile.close();

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
