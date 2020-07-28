#include <iostream>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() : Student() {
	studentDegree = NETWORKING;

}

NetworkStudent::NetworkStudent(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysLeft[],
	Degree degree) : Student(studentID, firstName, lastName, email, age, daysLeft) {
	studentDegree = NETWORKING;
}

Degree NetworkStudent::GetDegreeProgram() {
	return NETWORKING;
}


void NetworkStudent::print() {
	this->Student::print();
	cout << "Degree Program: Networking" << "\n";
}

void NetworkStudent::SetDegreeProgram(Degree setDegree) {
	this->studentDegree = setDegree;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}