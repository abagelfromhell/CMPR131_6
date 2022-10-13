#pragma once
#include "MyBag.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
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
	Course(int foo)
	{
		
	}
	void setCourseName(string newCourseName)
	{
		courseName = newCourseName;
	}
	string getCourseName()
	{
		return courseName;
	}
	void setIDBag(MyBag<int> newIDBag)
	{
		studentID = newIDBag;
	}
	MyBag<int> getIDBag()
	{
		return studentID;
	}
	void setStudentNames(MyBag<string> newNamesBag)
	{
		studentNames = newNamesBag;
	}
	MyBag<string> getStudentNames()
	{
		return studentNames;
	}
	void setStudentScores(MyBag<double> newScoresBag)
	{
		studentScores = newScoresBag;
	}
	MyBag<double> getStudentScores()
	{
		return studentScores;
	}
	void setStudentGrades(MyBag<char> newGradesBag)
	{
		studentGrades = newGradesBag;
	}
	MyBag<char> getStudentGrades()
	{
		return studentGrades;
	}
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
	const Course operator =(const Course& a)
	{
		
		courseName = a.courseName;
		studentID = a.studentID;
		studentNames = a.studentNames;
		studentScores = a.studentScores;
		studentGrades = a.studentGrades;
		
		return *this;
	}
	void addID(int newID)
	{
		studentID.insert(newID);
	}
	void addName(string newName)
	{
		studentNames.insert(newName);
	}
	void addScore(double newScore)
	{
		studentScores.insert(newScore);
	}
	void readFile(fstream& file)
	{
		string holder;

		getline(file, holder);
		cout << "\n\t\t" << holder;
		setCourseName(holder);
		holder.clear();

		getline(file, holder, ',');
		cout << "\n\t\t" << holder;
		studentID.insert(stoi(holder));
		holder.clear();

		getline(file, holder, ',');
		cout << "\n\t\t" << holder;
		studentNames.insert(holder);
		holder.clear();

		getline(file, holder);
		cout << "\n\t\t" << holder;
		studentScores.insert(stod(holder));
		setGradeLevel(stod(holder));
		holder.clear();

		

	}
	void display()
	{
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

};



