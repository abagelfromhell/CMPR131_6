#include <iostream>
#include "input.h"
#include "MyBag.h"
#include "Course.h"
#include <fstream>

using namespace std;

int menuOption();

char myBagMenu();
void nonTemplateSwitch();
void templateSwitch();

char applicationOfMenu();
void applicationOfSwitch();

int displayBagMenu(MyBag<Course> courseList);
int searchBagMenu();
int removeMenu(MyBag<Course> courseList);

//Preconditions : courseList must have elements to change, i should be the index for Course element
//Postconditions: will open user designated file and read records into MyBag<Course> courseList
void readCoursesFile(MyBag<Course>& courseList, int i);
//Preconditions : courseList must have elements with initialized values
//Postconditions: will search for Course element matching name or ID entered by user
void searchBag(MyBag<Course> courseList);
//Preconditions : courseList must have elements with initialized values
//Postconditions: will display courseList elements
void displayBag(MyBag<Course> courseList);
//Preconditions : courseList must have elements with initialized values
//Postconditions: will remove element matching user input ID
void removeBag(MyBag<Course>& courseList);

int main()
{
	do
	{
		switch (menuOption())
		{
		case 0: exit(1);
		case 1: system("cls"); nonTemplateSwitch(); cout << "\n\t\t"; system("pause"); system("cls"); break;
		case 2: system("cls"); templateSwitch(); cout << "\n\t\t"; system("pause"); system("cls"); break;
		case 3: system("cls"); applicationOfSwitch(); cout << "\n\t\t"; system("pause"); system("cls"); break;
		default: cout << "\nERROR: Invalid option.\n"; break;
		}
	} while (true);

	return 0;
}

int menuOption()
{
	cout << "\n\tCMPR131 Chapter 6: non-template and template Container by Tiffany Nguyen and Albert Mondragon";
	cout << "\n\t" << string(76, char(205));
	cout << "\n\t\t1> Non-template MyBag container of int";
	cout << "\n\t\t2> Template MyBag<double> container";
	cout << "\n\t\t3> Application using MyBag container";
	cout << "\n\t" << string(76, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(76, char(205));
	return inputInteger("\n\t\tOption: ", 0, 3);
}

char myBagMenu()
{
	cout << "\n\t" << string(76, char(205));
	cout << "\n\t\tA> clear";
	cout << "\n\t\tB> insert";
	cout << "\n\t\tC> search";
	cout << "\n\t\tD> remove";
	cout << "\n\t\tE> sort";
	cout << "\n\t\tF> display";
	cout << "\n\t" << string(76, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(76, char(205));
	return inputChar("\n\t\tOption: ");
}

void nonTemplateSwitch()
{
	cout << "\n\t1> Non-template MyBag of integers ";

	do
	{
		switch (myBagMenu())
		{
		case 'A':
		{

			break;
		}
		case 'B':
		{

			break;
		}
		case 'C':
		{

			break;
		}
		case 'D':
		{

			break;
		}
		case 'E':
		{

			break;
		}
		case 'F':
		{

			break;
		}
		case '0':
		{
			return;
		}
		default:
		{
			cout << "\n\t\t\tERROR: Invalid option.\n\t";
			break;
		}
		}
	} while (true);
}

void templateSwitch()
{
	cout << "\n\t2> Template MyBag<double> container";
	MyBag<double> numbersList;
	do
	{
		switch (myBagMenu())
		{
		case 'A':
		{
			numbersList.clear();
			cout << "\n\t\tMyBad is cleared of all elements.";
			break;
		}
		case 'B':
		{
			double value = inputDouble("\n\t\tEnter a value and insert into MyBag: ");
			numbersList.insert(value);
			cout << "\n\t\t" << value << " has been inserted into MyBag.";
			break;
		}
		case 'C':
		{
			if (numbersList.empty())
			{
				cout << "\n\t\tMyBag is empty.";
			}
			double value = inputDouble("\n\t\tEnter a value to search from MyBag: ");
			int index = numbersList.search(value);
			if (index != -1)
			{
				cout << "\n\t\tValue " << value << " is found at subscript #" << index << " from MyBag.";
			}
			else
			{
				cout << "\n\t\tValue " << value << " is not found from MyBag.";
			}
			break;
		}
		case 'D':
		{
			if (numbersList.empty())
			{
				cout << "\n\t\tMyBag is empty.";
			}
			int index = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, numbersList.size());
			cout << "\n\t\tValue " << numbersList.at(index) << " has been deleted from MyBag.";
			numbersList.remove(index);
			break;
		}
		case 'E':
		{
			if (numbersList.empty())
			{
				cout << "\n\t\tMyBag is empty.";
			}
			numbersList.sortArray();
			cout << "\n\t\tMybag contains these sorted integers: ";
			numbersList.display();
			break;
		}
		case 'F':
		{
			if (numbersList.empty())
			{
				cout << "\n\t\tMyBag is empty.";
			}
			cout << "\n\t\tMybag contains these sorted integers: ";

			numbersList.display();

			break;
		}
		case '0':
		{
			return;
		}
		default:
		{
			cout << "\n\t\t\tERROR: Invalid option.\n\t";
			break;
		}
		}
	} while (true);
}

char applicationOfMenu()
{
	cout << "\n\t3> Courses using MyBags of integers, strings, doubles, and chars";
	cout << "\n\t" << string(76, char(205));
	cout << "\n\t\tA> Specify the number of courses";
	cout << "\n\t\tB> Read in data file and insert into courses";
	cout << "\n\t\tC> Search for a student record from a course";
	cout << "\n\t\tD> Remove a student record from a course";
	cout << "\n\t\tE> Display course(s)";
	cout << "\n\t" << string(76, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(76, char(205));
	return inputChar("\n\t\tOption: ");
}

void applicationOfSwitch()
{
	MyBag<Course> courseList;
	do
	{
		switch (applicationOfMenu())
		{
		case 'A':
		{
			Course initializer;
			int numberOfCourses = inputInteger("\n\t\t1> Enter the number of courses: ");
			courseList.resize(initializer, numberOfCourses);
			cout << "\n\t\t" << numberOfCourses << " Course(s) has been created.\n";
			break;
		}
		case 'B':
		{
			if (courseList.size() == 0)
			{
				cout << "\n\t\tERROR: Number of courses has not been assigned.";
				cout << "\n";
				break;
			}
			for (int i = 0; i < courseList.size(); i++)
			{
				readCoursesFile(courseList, i);
			}
			break;
		}
		case 'C':
		{
			if (courseList.size() == 0)
			{
				cout << "\n\t\tERROR: MyBag is empty.";
				cout << "\n";
				break;
			}
			searchBag(courseList);
			break;
		}
		case 'D':
		{
			if (courseList.size() == 0)
			{
				cout << "\n\t\tERROR: MyBag is empty.";
				cout << "\n";
				break;
			}
			removeBag(courseList);
			break;
		}
		case 'E':
		{
			if (courseList.size() == 0)
			{
				cout << "\n\t\tERROR: MyBag is empty.";
				cout << "\n";
				break;
			}
			displayBag(courseList);
			break;
		}
		case '0':
		{
			return;
		}
		default:
		{
			cout << "\n\t\t\tERROR: Invalid option.\n\t";
			break;
		}
		}
	} while (true);
}

void readCoursesFile(MyBag<Course>& courseList, int i)
{
	bool read = false;
	do
	{
		fstream file;
		string fileName = inputString("\n\t\t2> Enter a data file name for course[" + to_string(i) + "] (STOP - return): ", true);
		if (fileName == "STOP")
		{
			cout << "\n\t\tFile reading has stopped.";
			system("pause");
			return;
		}
		file.open(fileName, ios::in || ios::beg);
		if ((file.fail()))
		{
			cout << "\n\t\tERROR: File, " << fileName << ", cannot be found. Please re-sepecify.\n\t\t";
			continue;
		}
		else
		{
			Course holder(1);
			string textHolder;

			getline(file, textHolder);	
			holder.setCourseName(textHolder);
			textHolder.clear();

			while (file.peek() != EOF)
			{
				
				getline(file, textHolder, ',');
				holder.addID(stoi(textHolder));
				textHolder.clear();

				getline(file, textHolder, ',');
				holder.addName(textHolder);
				textHolder.clear();

				getline(file, textHolder);
				holder.addScore(stod(textHolder));
				holder.setGradeLevel(stod(textHolder));
				textHolder.clear();

				read = true;
			}
			courseList.setArrayIndex(i, holder);
		}
		file.close();
		cout << "\n\t\tData from file, " << fileName <<" , has been read and stored into Courses[" << i << "].\n";
	} while (!read);
}

int searchBagMenu()
{
	cout << "\n\t\tC> Search By";
	cout << "\n\t\t" << string(76, char(205));
	cout << "\n\t\t\t1. ID Number";
	cout << "\n\t\t\t2. Name";
	cout << "\n\t\t\t0. Return";
	cout << "\n\t\t" << string(76, char(205));
	return inputInteger("\n\t\t\tOption: ", 0, 2);
}

void searchBag(MyBag<Course> courseList)
{
	
	do
	{
		switch (searchBagMenu())
		{
		case 1:
		{
			bool found = false;
			int index = -1;
			int courseNumber = -1;
			int searchThis = inputInteger("\n\t\tEnter a student ID to search: ");
			for (int i = 0; i < courseList.size(); i++)
			{
				index = ((courseList.at(i)).getIDBag()).search(searchThis);
				if (index != -1)
				{
					courseNumber = i;
					found = true;
				}
			}
			if (found)
			{
				cout << "\t\tID: " << searchThis << " has been found in Course: " << (courseList.at(courseNumber)).getCourseName();

			}
			else
			{
				cout << "\t\tNo student ID: " << searchThis << " found.";
			}
			cout << "\n";
			break;
		}
		case 2:
		{
			bool found = false;
			int index = -1;
			int courseNumber = -1;
			
			string userInput = inputString("\n\t\tEnter a student name to search: ", true);
			string searchThis = " " + userInput;
			for (int i = 0; i < courseList.size(); i++)
			{
				index = ((courseList.at(i)).getStudentNames()).search(searchThis);
				if (index != -1)
				{
					courseNumber = i;
					found = true;
				}
			}
			if (found)
			{
				cout << "\t\tName: " << searchThis << " has been found in Course: " << (courseList.at(courseNumber)).getCourseName();

			}
			else
			{
				cout << "\t\tNo student name: " << searchThis << " found.";
			}
			cout << "\n";
			break;
		}
		case 0:
			return;
		default:
			cout << "\n\t\tERROR: Invalid input.";
		}
	} while (true);
}

int displayBagMenu(MyBag<Course> courseList)
{
	cout << "\n\t\tCourse(s)";
	cout << "\n\t\t" << string(76, char(205));
	for (int i = 0; i < courseList.size(); i++)
	{
		cout << "\n\t\t " << i + 1 << ". " << (courseList.at(i)).getCourseName();
	}
	cout << "\n\t\t 4. All";
	cout << "\n\t\t 0. Return";
	cout << "\n\t\t" << string(76, char(205));
	return inputInteger("\n\t\tOption: ", 0, 4);
}

void displayBag(MyBag<Course> courseList)
{
	do
	{
		switch (displayBagMenu(courseList))
		{
		case 1:
		{
			if (courseList.size() < 1)
			{
				cout << "\n\t\tElement does not exist.";
				break;
			}
			Course holder;
			holder = courseList.at(0);
			holder.display();
			break;
		}
		case 2:
		{
			if (courseList.size() < 2)
			{
				cout << "\n\t\tElement does not exist.";
				break;
			}
			Course holder;
			holder = courseList.at(1);
			holder.display();
			break;
		}

		case 3:
		{
			if (courseList.size() < 3)
			{
				cout << "\n\t\tElement does not exist.";
				break;
			}
			Course holder;
			holder = courseList.at(2);
			holder.display();
			break;
		}

		case 4:
		{
			for (int i = 0; i < courseList.size(); i++)
			{
				courseList.at(i).display();
			}
			break;
		}

		case 0:
			return;
		default:
			cout << "\n\t\tERROR: Invalid input.";
			break;
		}
	} while (true);
}

int removeMenu(MyBag<Course> courseList)
{
	cout << "\n\t\t4> Course(s)";
	cout << "\n\t\t" << string(76, char(205));
	for (int i = 0; i < courseList.size(); i++)
	{
		cout << "\n\t\t " << i + 1 << ". " << (courseList.at(i)).getCourseName();
	}
	cout << "\n\t\t 0. Return";
	cout << "\n\t\t" << string(76, char(205));
	return inputInteger("\n\t\tOption: ", 0, 4);
}

void removeBag(MyBag<Course>& courseList)
{
	do
	{
		switch (removeMenu(courseList))
		{
		case 1:
		{
			if (courseList.size() < 1)
			{
				cout << "\n\t\tElement does not exist.";
				break;
			}			
			int searchThis = inputInteger("\n\t\tEnter a student ID to search: ");
			int index = courseList.at(0).getIDBag().search(searchThis);
			if (index != -1)
			{
				cout << "\t\tID: " << searchThis << " has been found in Course: " << (courseList.at(0)).getCourseName() << " and has been removed.";
				courseList.at(0).getIDBag().remove(index);
				courseList.at(0).getStudentNames().remove(index);
				courseList.at(0).getStudentScores().remove(index);
				courseList.at(0).getStudentGrades().remove(index);
				courseList.at(0).display();
			}
			else
			{
				cout << "\t\tNo student ID: " << searchThis << " found.";
			}
			cout << "\n";
			break;
		}
		case 2:
		{
			if (courseList.size() < 2)
			{
				cout << "\n\t\tElement does not exist.";
				break;
			}
			bool found = false;
			int index = -1;
			int courseNumber = -1;
			int searchThis = inputInteger("\n\t\tEnter a student ID to search: ");
			for (int i = 0; i < courseList.size(); i++)
			{
				index = ((courseList.at(i)).getIDBag()).search(searchThis);
				if (index != -1)
				{
					courseNumber = i;
					found = true;
				}
			}
			if (found)
			{
				cout << "\t\tID: " << searchThis << " has been found in Course: " << (courseList.at(courseNumber)).getCourseName() << " and has been removed.";
				courseList.remove(index);
			}
			else
			{
				cout << "\t\tNo student ID: " << searchThis << " found.";
			}
			cout << "\n";

			break;
		}

		case 3:
		{
			if (courseList.size() < 3)
			{
				cout << "\n\t\tElement does not exist.";
				break;
			}
			bool found = false;
			int index = -1;
			int courseNumber = -1;
			int searchThis = inputInteger("\n\t\tEnter a student ID to search: ");
			for (int i = 0; i < courseList.size(); i++)
			{
				index = ((courseList.at(i)).getIDBag()).search(searchThis);
				if (index != -1)
				{
					courseNumber = i;
					found = true;
				}
			}
			if (found)
			{
				cout << "\t\tID: " << searchThis << " has been found in Course: " << (courseList.at(courseNumber)).getCourseName() << " and has been removed.";
				courseList.remove(index);
			}
			else
			{
				cout << "\t\tNo student ID: " << searchThis << " found.";
			}
			cout << "\n";

			break;
		}
		case 0:
			return;
		default:
			cout << "\n\t\tERROR: Invalid input.";
			break;
		}
	} while (true);
}
