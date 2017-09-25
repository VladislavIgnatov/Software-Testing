// Team Polk Members: Vladislav Ignatov, Leonard Holloman, Walter Soulliere, Timothy Jones
// To compile on Linux use g++ -std=c+11 name_of_file.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXLEN 256

void save();

class Student {
	string fname, lname, unum, email;
	int pres, paper, proj;
public:
	Student(string, string, string, string, int, int, int);
	void set_fname(string);
	void set_lname(string);
	void set_unum(string);
	void set_email(string);
	void set_pres(int);
	void set_paper(int);
	void set_proj(int);
	string get_lname() { return lname; };
	string get_fname() { return fname; };
	string get_unum() { return unum; };
	string get_email() { return email; };
	int get_pres() { return pres; };
	int get_paper() { return paper; };
	int get_proj() { return proj; };
};

Student::Student(string x, string v, string y, string z, int a = 0, int b = 0, int c = 0) {
	fname = x;
	lname = v;
	unum = y;
	email = z;
	pres = a;
	paper = b;
	proj = c;
}

void Student::set_fname(string x)
{
	fname = x;
}

void Student::set_lname(string x){
	lname = x;
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
		cout << i+1 << ". " << database[i].get_fname() << "\t" << database[i].get_lname() << "\t" << database[i].get_unum() << "\t" << database[i].get_email() << "\tPresentaion:";
		cout << database[i].get_pres() << "\tPaper:" << database[i].get_paper() << "\tProject:" << database[i].get_proj() << endl;
	}
}

// Write student data or change it
void WRITE() {
	DISPLAY();
	cout << "Write data" << endl;
}

// Adds student to the database
void ADD() {
	string nfName, nlName, nUnum, nEmail;
	cout << "Student First Name:";
	cin >> nfName;
	cout << endl << "Student's Last Name:";
	cin >> nlName;
	cout << endl << "Student's UNumber:";
	cin >> nUnum;
	cout << endl << "Student's Email:";
	cin >> nEmail;
	Student nStu = Student(nfName, nlName, nUnum, nEmail, 0, 0, 0);
	database.push_back(nStu);
	DISPLAY();
	save();
}

// Delete student from database
void DELETE() {
	int input = 0;
	
	DISPLAY();
	cout << "Enter the Number of the student that you want to delete: ";
	cin >> input;
	
	cout << endl << "Student Deleted: " << database[input -1].get_fname() << " " << database[input -1].get_lname() << endl << endl;
	database.erase(database.begin() + input - 1);
	DISPLAY();
}

// Saerch for a student
void SEARCH() {
	
	string name;
	DISPLAY();
	cout << "SEARCH for a Student" << endl;
	cin >> name;
	
	
		//search for name. If found, print student info
		for (int i = 0; i < database.size(); i++) {
			
			//using string compare to find name
			if (name.compare(database[i].get_lname()) ==0){
				
				cout << "Match Found!" << endl;
				cout << database[i].get_lname() << " " << database[i].get_unum() << " " <<database[i].get_email();
				cout << " " << database[i].get_pres() << " " << database[i].get_paper() << " " << database[i].get_proj();
				cout << endl;
				
				
			    
			}
	
			if((database.size() -1) == i){
				
   				cout << endl << name << " is not listed in the database" << endl;
			}
		}
			
}

// Saerch for a student
void UPDATE() {
	DISPLAY();
	cout << "UPDATE a Students Info" << endl;
}

void save(){
	ofstream outfile;
	outfile.open("database.txt");
	for(unsigned int i=0; i < database.size(); i++){
		outfile << database[i].get_fname() << "," << database[i].get_lname() << "," << database[i].get_unum() << "," << database[i].get_email() << "," << database[i].get_pres() << "," << database[i].get_paper() << "," << database[i].get_proj() << endl;
	}
	outfile.close();
}

int main() {
	FILE *fp;
	char str[MAXLEN];
	char *fn;
	char *ln;
	char *em;
	char *un;
	char *pres;
	char *pap;
	char *project;
	
	string line;

	//ifstream db("database.txt");

	//if (db.is_open()) {//checks if it is open
	if(fp = fopen("database.txt", "r")){

		while(fgets(str, MAXLEN, fp) != NULL){
			fn = strtok(str, ",");
			ln = strtok(NULL, ",");
			un = strtok(NULL, ",");
			em = strtok(NULL, ",");
			pres = strtok(NULL, ",");
			pap = strtok(NULL, ",");
			project = strtok(NULL, ",");
			Student tmp = Student(fn, ln, un, em, atoi(pres), atoi(pap), atoi(project));
			database.push_back(tmp);
			
		}	

		/*while (getline(db, line))//grabs a line out of the document
		{
			string hold[7] = {};
			//char *next_token = NULL;
			char *token = strtok((char*)line.c_str(), ",");
			int count = 0;

			while (token) {
				if (token != NULL)
				{
					hold[count++] = token;
					token = strtok(NULL, ",");
				}
			}
			int a, b, c;
			a = stoi(hold[4]);
			b = stoi(hold[5]);
			c = stoi(hold[6]);
			Student tmp = Student(hold[0], hold[1], hold[2], hold[3], a, b, c);
			//cout << atoi(hold[5]) << endl;
			database.push_back(tmp);
		}*/

		//db.close();
	}
	else {
		// file decleration
		ofstream outfile;

		// Creat file 
		outfile.open("database.txt");

		// Populating the file
		outfile << "Rick,Sanchaz,u01234567,regularrick@gmail.com,6,6,6" << endl;
		outfile << "Morty,Smith,u76543210,morty@gmail.com,3,3,2" << endl;
		outfile << "Summer,Smith,u88965238,summer@gmail.com,4,4,3" << endl;
		outfile << "Walter,White,u96571368,hizenburg@gmail.com,6,6,6" << endl;
		outfile << "Jesse,Pinkman,u79269858,pinkman@gmail.com,1,2,1" << endl;

		outfile.close();
		
		// TODO this needs to be cleaned up atm it is a bandaid
		Student tmp = Student("Rick", "Sanchaz", "u01234567", "regularrick@gmail.com", 6, 6, 6);
		database.push_back(tmp);
		tmp = Student("Morty", "Smith", "u76543210", "morty@gmail.com", 3, 3, 2);
		database.push_back(tmp);
		tmp = Student("Summer", "Smith", "u88965238", "summer@gmail.com", 4, 4, 3);
		database.push_back(tmp);
		tmp = Student("Walter" ,"White", "u96571368", "hizenburg@gmail.com", 6, 6, 6);
		database.push_back(tmp);
		tmp = Student("Jesse", "Pinkman", "u79269858", "pinkman@gmail.com", 1, 2, 1);
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
