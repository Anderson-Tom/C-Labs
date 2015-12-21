/*
* tom Anderson
* C00174844
* Write a program that takes as input the number of a month and outputs the name 
* of that month. (Write two versions: one  with an if statement and one with a 
* switch statement).
*/

#include <iostream>
#include <cstdlib>
#include <limits.h>
using namespace std;

int getMonthNum();
void printMonthName(int monthNum);
int main()
{
	
	int monthNum = -1; 	
	
	while (monthNum != 0)
	{
		cout << "Enter a number from 1 to 12 - 0 to quit : ";
		monthNum = getMonthNum();
		printMonthName(monthNum);
	}
	system("pause");
	return 0;
}

int getMonthNum()
{

	int inChar = 0;
	unsigned int num = 0;

	bool hasMore = true;
	int multiple = 1;
	while (hasMore)
	{
		inChar = getchar();
		//Check for enter pressed
		if (inChar != 10)
		{
			inChar = inChar - 48;
			//Check we have a digit 
			if (inChar >= 0 && inChar <= 9)
			{
				num = num * multiple + inChar;
				multiple = 10;
			}
			else
			{
				printf("Bad input - please enter positve digits only!!\n");
				fflush(stdin);
				return getMonthNum();
			}
			//check that the total so far is between 1 and 12
			if (num < 0 || num > 12)
			{
				printf("Please enter a number betwwen 0 and 12\n");
				fflush(stdin);
				return getMonthNum();
			}
		}
		else
		{
			hasMore = false;
		}
	}
	return (int)num;
}

void printMonthName( int monthNum)
{
	if (monthNum == 1)
	{
		cout << "January" << endl;
	}
	else if (monthNum == 2)
	{
		cout << "February" << endl;
	}
	else if (monthNum == 3)
	{
		cout << "March" << endl;
	}
	else if (monthNum == 4)
	{
		cout << "April" << endl;
	}
	else if (monthNum == 5)
	{
		cout << "May" << endl;
	}
	else if (monthNum == 6)
	{
		cout << "June" << endl;
	}
	else if (monthNum == 7)
	{
		cout << "July" << endl;
	}
	else if (monthNum == 8)
	{
		cout << "August" << endl;
	}
	else if (monthNum == 9)
	{
		cout << "September" << endl;
	}
	else if (monthNum == 10)
	{
		cout << "October" << endl;
	}
	else if (monthNum == 11)
	{
		cout << "November" << endl;
	}
	else if (monthNum == 12)
	{
		cout << "December" << endl;
	}

}

	



	