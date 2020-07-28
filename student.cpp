#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysLeftSize; i++) this->daysLeft[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysLeft[]) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysLeftSize; i++) this->daysLeft[i] = daysLeft[i];
}

// ACCESSORS

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDaysLeft() {
	return daysLeft;
}


// MUTATORS

void Student::SetStudentID(string id) {
	this->studentID = id;
}

void Student::SetFirstName(string fname) {
	this->firstName = fname;
}

void Student::SetLastName(string lname) {
	this->lastName = lname;
}

void Student::SetEmail(string email) {
	this->email = email;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysLeft(int daysLeft[]) {
	for (int i = 0; i < daysLeftSize; i++)
		this->daysLeft[i] = daysLeft[i];
}

void Student::print() {

	int* numDaysLeft = GetDaysLeft();

	cout << left << setw(5) << studentID;
	cout << left << setw(7) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(25) << email;
	cout << left << setw(5) << "Age: " << age << "  ";
	cout << left << setw(10) << "daysInCourse: {" << *numDaysLeft << ", " << *(numDaysLeft + 1) << ", " << *(numDaysLeft + 2) << "}  ";
}

Student::~Student() {

}