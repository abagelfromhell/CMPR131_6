#pragma once
#include "MyBag.h"
#include <string>

using namespace std;

class Course
{
private:
	string courseName;
	MyBag<int> studentID;
	MyBag<string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> studentGrades;
public:
	Course()
	{
		courseName = "Unknown";
		studentID.insert(-1);
		studentNames.insert("unkown");
		studentScores.insert(-0.1);
		studentGrades.insert('Z');

	}
	void setCourseName(string newCourseName)
	{
		courseName = newCourseName;
	}
	string getCourseName()
	{
		return courseName;
	}
	int getIDBag()
	{
		
	}
	Course operator =(const Course& a)
	{
	}
};

