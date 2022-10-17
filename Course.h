#pragma once
#include "MyBag.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

using namespace templateVersion;

class Course
{
private:
	string courseName;
	MyBag<int> studentID;
	MyBag<string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> studentGrades;
public:
	//Preconditions : N/A
	//Postconditions: Initializes member variables
	Course()
	{
		courseName = "Unknown";
		studentID.insert(-1);
		studentNames.insert("unkown");
		studentScores.insert(-0.1);
		studentGrades.insert('Z');

	}
	//Preconditions : N/A
	//Postconditions: N/A
	Course(int foo)
	{

	}
	//Preconditions : newCourseName must be initialized
	//Postconditions: newCourseName will be copied to courseName 
	void setCourseName(string newCourseName)
	{
		courseName = newCourseName;
	}
	//Preconditions : N/A
	//Postconditions: returns string courseName
	string getCourseName()
	{
		return courseName;
	}
	//Preconditions : newIDBag must be MyBag<int> container
	//Postconditions: will copy newIDBag to studentID
	void setIDBag(MyBag<int> newIDBag)
	{
		studentID = newIDBag;
	}
	//Preconditions : N/A
	//Postconditions: will return MyBag<int> studentID
	MyBag<int> getIDBag()
	{
		return studentID;
	}
	//Preconditions : newNamesBag must be MyBag<string> container
	//Postconditions: will copy newNamesBag to studentNames
	void setStudentNames(MyBag<string> newNamesBag)
	{
		studentNames = newNamesBag;
	}
	//Preconditions : N/A
	//Postconditions: will return MyBag<string> studentNames
	MyBag<string> getStudentNames()
	{
		return studentNames;
	}
	//Preconditions : newScoresBag must be MyBag<double> container
	//Postconditions: will copy newScoresBag to studentScores
	void setStudentScores(MyBag<double> newScoresBag)
	{
		studentScores = newScoresBag;
	}
	//Preconditions : N/A
	//Postconditions: will return MyBag<double> studentScores 
	MyBag<double> getStudentScores()
	{
		return studentScores;
	}
	//Preconditions : newGradesBag must be MyBag<char> container
	//Postconditions: will copy newGradesBag to studentGrades
	void setStudentGrades(MyBag<char> newGradesBag)
	{
		studentGrades = newGradesBag;
	}
	//Preconditions : N/A
	//Postconditions: will return MyBag<char> studentGrades
	MyBag<char> getStudentGrades()
	{
		return studentGrades;
	}
	//Preconditions : double score should be a score based on a 100.0 scale
	//Postconditions: will add grade leter based on score to MyBag<char> studentGrades
	void setGradeLevel(double score)
	{
		if (score > 89.9)
		{
			studentGrades.insert('A');
		}
		else if (score > 79.9)
		{
			studentGrades.insert('B');

		}
		else if (score > 69.9)
		{
			studentGrades.insert('C');

		}
		else if (score > 59.9)
		{
			studentGrades.insert('D');

		}
		else
		{
			studentGrades.insert('F');

		}
	}
	//Preconditions : right of the operator should be Course type with initalized values
	//Postconditions: member variables will be set equal to Course a
	const Course operator =(const Course& a)
	{

		courseName = a.courseName;
		studentID = a.studentID;
		studentNames = a.studentNames;
		studentScores = a.studentScores;
		studentGrades = a.studentGrades;

		return *this;
	}
	//Preconditions : newID must be initialized
	//Postconditions: will add newID to MyBag<int> studentID
	void addID(int newID)
	{
		studentID.insert(newID);
	}
	//Preconditions : newName must be initialized
	//Postconditions: will add newName to MyBag<string> studentNames
	void addName(string newName)
	{
		studentNames.insert(newName);
	}
	//Preconditions : newScore must be initialized
	//Postconditions: will add newScore to MyBag<double> studentScores
	void addScore(double newScore)
	{
		studentScores.insert(newScore);
	}
	//Preconditions : Course must have initialized values
	//Postconditions: Will display course member values
	void display()
	{
		if (studentID.size() == 0)
		{
			cout << "\n\t\t"<< courseName <<" has no student records.";
			return;
		}
		cout << "\n\t\t" << courseName;
		cout << "\n\t\tIndex    StudentID                      Name    Score   Grade   ";
		for (int i = 0; i < studentID.size(); i++)
		{
			cout << "\n\t\t";
			cout << setw(5) << i << setw(13) << studentID.at(i) << setw(26) << studentNames.at(i) << setw(9) << studentScores.at(i) << setw(8) << studentGrades.at(i);

		}

		double sum = 0;
		for (int i = 0; i < studentScores.size(); i++)
		{
			sum += studentScores.at(i);
		}
		char letterGradeAverage = 'Z';
		if (sum / studentScores.size() > 89.9)
		{
			letterGradeAverage = 'A';
		}
		else if (sum / studentScores.size() > 79.9)
		{
			letterGradeAverage = 'B';

		}
		else if (sum / studentScores.size() > 69.9)
		{
			letterGradeAverage = 'C';

		}
		else if (sum / studentScores.size() > 59.9)
		{
			letterGradeAverage = 'D';

		}
		else
		{
			letterGradeAverage = 'E';

		}
		cout << "\n\n\t\tAverage score and grade: " << fixed << setprecision(1) << sum / studentScores.size() << " " << letterGradeAverage;
		cout << "\n";

	}
	//Preconditions : index must be in a valid element index in MyBag container
	//Postconditions: will remove element at index
	void remove(int index)
	{

		studentID.remove(index);
		studentNames.remove(index);
		studentScores.remove(index);
		studentGrades.remove(index);
	}
};



