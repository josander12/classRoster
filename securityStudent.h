#pragma once
#include <string>
#include "student.h"
using namespace std;

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

class SecurityStudent : public Student {

public:

	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysLeft[],
		Degree studentDegree
	);

	Degree GetDegreeProgram();

	void SetDegreeProgram(Degree setDegree);

	void print();

	~SecurityStudent();

};

#endif