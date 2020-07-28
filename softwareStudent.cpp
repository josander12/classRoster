#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() : Student() {
	studentDegree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysLeft[],
	Degree degree) : Student(studentID, firstName, lastName, email, age, daysLeft) {
	studentDegree = SOFTWARE;
}

Degree SoftwareStudent::GetDegreeProgram() {
	return SOFTWARE;
}


void SoftwareStudent::print() {
	this->Student::print();
	cout << "Degree Program: Software" << "\n";
}

void SoftwareStudent::SetDegreeProgram(Degree setDegree) {
	this->studentDegree = setDegree;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}