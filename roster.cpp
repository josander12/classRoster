#include <string>
#include <iostream>
#include "roster.h"

using namespace std;

Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

void Roster::parse(string row) {
	// Setting the degree for each type:

	if (lastIndex < capacity) {
		lastIndex++;
		
		Degree degree;

		if (row.substr(row.length() - 8, 8) == "SOFTWARE") {
			degree = SOFTWARE;
		}

		else if (row.substr(row.length() - 8, 8) == "SECURITY") {
			degree = SECURITY;
		}

		else if (row.substr(row.length() - 7, 7) == "NETWORK") {
			degree = NETWORKING;
		}

		// parse student ID

		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		// parse first name

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fname = row.substr(lhs, rhs - lhs);

		// parse last name

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lname = row.substr(lhs, rhs - lhs);

		// parse email

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		// parse age

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		// parse days1

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days1 = stoi(row.substr(lhs, rhs - lhs));
		
		// parse days2

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days2 = stoi(row.substr(lhs, rhs - lhs));

		// parse days3

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days3 = stoi(row.substr(lhs, rhs - lhs));

		add(sID, fname, lname, email, age, days1, days2, days3, degree);
	}
}

void Roster::add(string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	Degree degree) {

	int daysLeft[Student::daysLeftSize];
	daysLeft[0] = daysInCourse1;
	daysLeft[1] = daysInCourse2;
	daysLeft[2] = daysInCourse3;

	if (degree == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysLeft,
			degree);
	}

	else if (degree == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysLeft,
			degree);
	}
	
	else if (degree == NETWORKING) {
		classRosterArray[lastIndex] = new NetworkStudent(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysLeft,
			degree);
	}
}

void Roster::remove(string studentID) {

	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {

		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}

	if (found == false) {
		cout << "Such a student with this ID was not found." << endl;
	}
}

void Roster::printAll() {

	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::printDaysInCourse(string studentID) {
	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {
		
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			int* p = classRosterArray[i]->GetDaysLeft();
			cout << "Average days left for student " << studentID << " is " << ((static_cast<double>(p[0]) + static_cast<double>(p[1]) + static_cast<double>(p[2])) / 3) << endl;
		}
	}
}

void Roster::printInvalidEmails() {

	cout << "Displaying invalid emails..." << endl;
	bool any = false;
	for (int i = 0; i <= lastIndex; i++) {
		any = false;
		string currentEmail = classRosterArray[i]->GetEmail();

		if ((currentEmail.find(" ") != string::npos) || (currentEmail.find("@") == string::npos) || (currentEmail.find(".") == string::npos)) {
			any = true;
			cout << currentEmail << " (Student ID: " << classRosterArray[i]->GetStudentID() << " - ";

			if (currentEmail.find(" ") != string::npos) {
				cout << "Email cannot contain blank spaces.)" << endl;
			}

			else if (currentEmail.find("@") == string::npos) {
				cout << "Email must contain an @ symbol.)" << endl;
			}

			else if (currentEmail.find(".") == string::npos) {
				cout << "Email must contain a period in the domain name.)" << endl;
			}
		}
		any = true;
	}
	if (!any) cout << "All emails are valid." << endl;
}

void Roster::printByDegreeProgram(int degreeProgram) {

	cout << "Printing all students in the roster with degree: " << degreeTypeStrings[degreeProgram] << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
	}

}

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

int main() {

	int numStudents = 5;

	const string studentData[] = {
	"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Joe,Anderson,jand629@wgu.edu,30,30,30,30,SOFTWARE",
	};

	// Building the roster class

	Roster* classRoster = new Roster(numStudents);

	cout << "Parsing data and building roster..." << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->parse(studentData[i]);
	}

	cout << "Done." << endl;
	
	cout << "Displaying roster..." << endl;
	classRoster->printAll();
	cout << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	cout << "Printing average days left for each student...";
	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->GetStudentID());
	}
	cout << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	cout << "Removing A3..." << endl;
	classRoster->remove("A3");
	cout << "A3 removed.  Reprinting student roster..." << endl;
	classRoster->printAll();
	cout << endl;
	cout << "Removing A3..." << endl;
	classRoster->remove("A3");
	cout << endl;

	system("pause");
	return 0;
}

