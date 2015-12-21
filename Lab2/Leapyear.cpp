
/*Tom Anderson
* C00174844
* Write a program called leapyear.cpp that will input a stream of numbers, each corresponding to some year 
* (any value greater than 0 and up to implementation defined limits for an int) and outputs the message 
* “this is a leap year” or “this is not a leap year” as appropriate. A year is a leap year if it is 
* divisible by 4 and not 100, unless it is also divisible by 400. The program will terminate when a 
* zero is input. Keep your code as short, efficient and readable as possible. The appropriate error 
* checking must.....
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int getDigits()
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
				printf("Bad input - please enter positve digits only [0-9]\n");
				fflush(stdin);
				return getDigits();
			}
			//check that the total so far will fit in an int
			if (num > INT_MAX)
			{
				printf("Please enter a number betwwen 0 and %d\n", INT_MAX);
				fflush(stdin);
				return getDigits();
			}
		}
		else
		{
			hasMore = false;
		}
	}
	return (int) num;
}

bool isLeapYear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0))
	{
		return true;
	}
	else if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}	
}

int main()
{
		int year = -1;
		while (year != 0)
		{
			printf("Enter a year to test for leapedness : ");
			year = getDigits();
			if (isLeapYear(year))
			{
				printf("%d is a leap year\n", year);
			}
			else
			{
				printf("%d is not a leap year\n", year);
			}
		} 
		system("pause");
}

