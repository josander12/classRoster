#pragma once
#include <string>
#include "student.h"
using namespace std;

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

class SoftwareStudent : public Student {

	public:
		
		SoftwareStudent();
		SoftwareStudent(
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

		~SoftwareStudent();

};

#endif