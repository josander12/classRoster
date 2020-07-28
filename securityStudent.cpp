#include <iostream>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent() : Student() {
	studentDegree = SECURITY;

}

SecurityStudent::SecurityStudent(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysLeft[],
	Degree degree) : Student(studentID, firstName, lastName, email, age, daysLeft) {
	studentDegree = SECURITY;
}

Degree SecurityStudent::GetDegreeProgram() {
	return SECURITY;
}


void SecurityStudent::print() {
	this->Student::print();
	cout << "Degree Program: Security" << "\n";
}

void SecurityStudent::SetDegreeProgram(Degree setDegree) {
	this->studentDegree = setDegree;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}