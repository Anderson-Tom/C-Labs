// integerPalindrome.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
using namespace std;
int getDigits();
bool isPalindrome(int);

int main()
{
	int testNum = -1;
	while (testNum != 0)
	{
		cout << "Enter a number to test - 0 to quit" << endl;
		testNum = getDigits();
		if (isPalindrome(testNum))
		{
			cout << testNum << " is a palindrome" << endl;
		}
		else
		{
			cout << testNum << " is NOT a palindrome" << endl;
		}
		
	}
	system("pause");
	return 0;
}

bool isPalindrome( int testNum)
{
	int temp = testNum;
	int reverse = 0;
	while (temp > 0)
	{
		reverse = reverse * 10;
		reverse = reverse + temp % 10;
		temp =  temp / 10;
	}
	if (reverse == testNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}
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
				printf("Bad input - please enter positive digits only [0-9]\n");
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
	return (int)num;
}