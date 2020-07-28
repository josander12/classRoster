#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;



#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:

	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysLeft[]);
	

	const static int daysLeftSize = 3;

	// ACCESSORS

	string GetStudentID() const; 
	string GetFirstName() const; 
	string GetLastName() const; 
	string GetEmail() const; 
	int GetAge() const; 
	int* GetDaysLeft();
	virtual Degree GetDegreeProgram() = 0;

	// MUTATORS

	void SetStudentID(string id); 
	void SetFirstName(string fname); 
	void SetLastName(string lname); 
	void SetEmail(string email); 
	void SetAge(int age); 
	void SetDaysLeft(int daysLeft[]);
	virtual void SetDegreeProgram(Degree setDegree) = 0;


	virtual void print() = 0;
	
	// DESTRUCTOR
	~Student();

protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysLeft[daysLeftSize];
	Degree studentDegree;
};

#endif