
/*Tom Anderson
* C00174844
* Write a program called swopcase.cpp that will input a line of text 
* from the user and return that line with all uppercase letters converted
* to lowercase, all lowercase letters converted to uppercase and all other
* characters left unchanged. You may not #include <ctype.h> in your program
* or use Strings or arrays, you must instead implement any of the functions
* from it that you need to complete this task. .
*/
#include <iostream>
#include <cstdlib>
using namespace std;

bool isUpper(char testChar);
bool isLower(char testChar);
char toUpper(char startChar);
char toLower(char startChar);
void getInput();

int main()
{
	getInput();
	system("pause");
	return 0;
}

bool isUpper(char testChar)
{	
	return (testChar <= 'Z' && testChar >= 'A');
}


bool isLower(char testChar)
{
	return (testChar <= 'z' && testChar >= 'a');
}

char toUpper(char testChar)
{
	if (isLower(testChar))
	{
		return testChar - 32;
	}
	else
	{
		return testChar;
	}
}


char toLower(char testChar)
{
	if (isUpper(testChar))
	{
		return testChar + 32;
	}
	else
	{
		return testChar;
	}
}

void getInput()
{

	char inChar ;
	unsigned int num = 0;

	bool hasMore = true;
	int multiple = 1;
	while (hasMore)
	{
		inChar = getchar();
		//Check for enter
		if (inChar != 10)
		{
			if (isLower(inChar))
			{
				inChar = toUpper(inChar);
			}
			else if (isUpper(inChar))
			{
				inChar = toLower(inChar);
			}
			//nothing will be written to the terminal until we are finished with input
			//
			printf("%c",inChar);
		}
		else
		{
			hasMore = false;
			printf("\n");
		}
	}
}