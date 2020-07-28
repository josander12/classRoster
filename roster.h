#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
using namespace std;

#ifndef ROSTER_H
#define ROSTER_H

class Roster {
	
public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parse(string row);
	void add(string studentID, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		int daysInCourse1, 
		int daysInCourse2, 
		int daysInCourse3, 
		Degree degree);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	
	~Roster();

private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;
};

#endif 