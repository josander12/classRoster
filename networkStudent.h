#pragma once
#include <string>
#include "student.h"
using namespace std;

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

class NetworkStudent : public Student {

public:

	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();

};

#endif