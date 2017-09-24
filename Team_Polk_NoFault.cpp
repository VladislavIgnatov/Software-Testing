// Team Polk Members: Vladislav Ignatov, Leonard Holloman, Walter Soulliere, Timothy Jones
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

class Student {
	string name, unum, email;
	int pres, paper, proj;
public:
	Student(string, string, string, int, int, int);
	void set_name(string);
	void set_unum(string);
	void set_email(string);
	void set_pres(int);
	void set_paper(int);
	void set_proj(int);
	string get_name() { return name; };
	string get_unum() { return unum; };
	string get_email() { return email; };
	int get_pres() { return pres; };
	int get_paper() { return paper; };
	int get_proj() { return proj; };
};

Student::Student(string x, string y, string z, int a = 0, int b = 0, int c = 0) {
	name = x;
	unum = y;
	email = z;
	pres = a;
	paper = b;
	proj = c;
}

void Student::set_name(string x)
{
	name = x;
}

void Student::set_unum(string x)
{
	unum = x;
}

void Student::set_email(string x)
{
	email = x;
}

void Student::set_pres(int x)
{
	pres = x;
}

void Student::set_paper(int x)
{
	paper = x;
}

void Student::set_proj(int x)
{
	proj = x;
}

vector<Student> database;

// Displays student data, all of the class or just one student. READ ONLY. INDEPENDENT FUNCTION
void DISPLAY() {
	cout << "--------------Student Information--------------" << endl << endl;

	for (int i = 0; i < database.size(); i++) {
		cout << database[i].get_name() << "  " << database[i].get_unum() << "  " << database[i].get_email() << "  Presentaion: ";
		cout << database[i].get_pres() << "  Paper: " << database[i].get_paper() << "  Project: " << database[i].get_proj() << endl;
	}
}

// Write student data or change it
void WRITE() {
	DISPLAY();
	cout << "Write data" << endl;
}

// Adds student to the database
void ADD() {
	cout << "ADD STUDENT" << endl;
}

// Delete student from database
void DELETE() {
	cout << "DELETE STUDENT" << endl;
}

// Saerch for a student
void SEARCH() {
	DISPLAY();
	cout << "SEARCH for a Student" << endl;
}

// Saerch for a student
void UPDATE() {
	DISPLAY();
	cout << "UPDATE a Students Info" << endl;
}

int main() {
	
	string line;

	ifstream db("database.txt");

	if (db.is_open()) {//checks if it is open
		while (getline(db, line))//grabs a line out of the document
		{
			string hold[6] = {};
			//char *next_token = NULL;
			char *token = strtok((char*)line.c_str(), ",");
			int count = 0;

			while (token) {
				if (token != NULL)
				{
					hold[count++] = token;
					token = strtok_s(NULL, ",");
				}
			}
			
			Student tmp = Student(hold[0], hold[1], hold[2], stoi(hold[3]), stoi(hold[4]), stoi(hold[5]));
			database.push_back(tmp);
		}

		db.close();
	}
	else {
		// file decleration
		ofstream outfile;

		// Creat file 
		outfile.open("database.txt");

		// Populating the file
		outfile << "Rick Sanchaz,u01234567,regularrick@gmail.com,6,6,6" << endl;
		outfile << "Morty Smith,u76543210,morty@gmail.com,3,3,2" << endl;
		outfile << "Summer Smith,u88965238,summer@gmail.com,4,4,3" << endl;
		outfile << "Walter White,u96571368,hizenburg@gmail.com,6,6,6" << endl;
		outfile << "Jesse Pinkman,u79269858,pinkman@gmail.com,1,2,1" << endl;

		outfile.close();
		
		// TODO this needs to be cleaned up atm it is a bandaid
		Student tmp = Student("Rick Sanchaz", "u01234567", "regularrick@gmail.com", 6, 6, 6);
		database.push_back(tmp);
		tmp = Student("Morty Smith", "u76543210", "morty@gmail.com", 3, 3, 2);
		database.push_back(tmp);
		tmp = Student("Summer Smith", "u88965238", "summer@gmail.com", 4, 4, 3);
		database.push_back(tmp);
		tmp = Student("Walter White", "u96571368", "hizenburg@gmail.com", 6, 6, 6);
		database.push_back(tmp);
		tmp = Student("Jesse Pinkman", "u79269858", "pinkman@gmail.com", 1, 2, 1);
		database.push_back(tmp);
	}

	int choice = 0;

	while (1) {
		
		cout << "\nWelcome to USF Class-Roll System\n";
		cout << "1: READ Student Data\n";
		cout << "2: WRITE Student Data\n";
		cout << "3: ADD Student\n";
		cout << "4: DELETE Student\n";
		cout << "5: SEARCH Student\n";
		cout << "6: UPDATE Student\n";
		cout << "7: EXIT\n";
		cout << "Enter in a number (1-7): ";

		cin >> choice;

		cout << "\n";

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
		case(7):
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
