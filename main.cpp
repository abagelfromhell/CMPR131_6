#include <iostream>
#include "input.h"
#include "MyBag.h"

using namespace std;

int menuOption();

char myBagMenu();
void nonTemplateSwitch();
void templateSwitch();

char applicationOfMenu();
void applicationOfSwitch();

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
	do
	{
		switch (applicationOfMenu())
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