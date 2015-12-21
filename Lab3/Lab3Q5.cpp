/*
*	Lab	: 3
*	Exercise: 5
*	Student	: Tom Anderson
*	Number	: C00174844
*	Date	:10/11/2015
*
*
*/

#include <iostream>

using namespace std;

void getString(char *);
int countWords(char * );
bool isValidChar(char *);

int main()
{

	char testString[1024];
	cout << "Enter a string to count the valid words of" << endl;
	getString(testString);
	cout << "There were " << countWords(testString) << " valid words in the string" << endl;
	system("pause");
	return 0;
}

//method the put keyboard input inta a char array passed as a pointer
void getString(char * arrayStart)
{
	bool foundSpace = false;
	char inChar;
	inChar = getchar();
	//as long as we dont have enter pressed add the input to the char array
	//and increase the pointer point at the next char in the array
	while (inChar != 10)
	{
		*arrayStart = inChar;
		arrayStart++;
		inChar = getchar();
	}
	//terminate string with /0 ,also if we have an emty string we end up with /0 
	//which we can handle in our other functions
	*arrayStart = '\0';
}

int countWords(char * testString)
{
	int count = 0;
	
	while (*testString  != '\0')
	{
		bool validWord;
		//traverse spaces
		while (*testString == ' ' && *testString != '\0')
		{
			testString++;
		}
		
		if (*testString != '\0')
		{
			//we have reached a series of chararcters, assume its a valid word until a character fails the test for validity 
			validWord = true;
			while (*testString != ' ' && *testString != '\0')  //traverse the string intill we meet another space or EOL
			{
				if (!isValidChar(testString))
				{
					validWord = false;
				}
				testString++;
			}
			if (validWord)
			{
				count++;
			}
		}
	}
	return count;
}

//check if a character is a letter 
bool isValidChar(char * testChar)
{
	if (*testChar >= 'a' && *testChar <= 'z')
	{
		return true;
	}
	else if (*testChar >= 'A' && *testChar <= 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
}