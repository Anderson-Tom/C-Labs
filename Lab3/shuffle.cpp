/*
*	Lab	: 3
*	Exercise: 6
*	Student	: Tom Anderson
*	Number	: C00174844
*	Date	: 11/11/2015
*
*
*/

#include <iostream>

using namespace std;


void getString(char *);
void shuffle(char *, char*);

int main()
{
	char input[1024];
	char output[1024];
	getString(input);
	shuffle(input, output);
	cout << output << endl;
	system("pause");
	return 0;
}

//method the put keybord input inta a char array passed as a pointer
void getString(char * arrayStart)
{
	bool foundSpace = false;
	char inChar;
	int charCount = 1;
	inChar = getchar();
	//as long as we dont have enter pressed add the input to the char array
	//and increase the pointer point at the next char in the array, space allowing
	while (inChar != 10 && charCount < 1024)
	{
		*arrayStart = inChar;
		arrayStart++;
		charCount++;
		inChar = getchar();
	}
	//terminate string with /0 ,also if we have an emty string we end up with /0 
	//which we can handle in our other functions
	*arrayStart = '\0';
}

void shuffle(char * input, char * output)
{
	bool hasAsterix = false;
	char * inputStart;
	inputStart = input;
	int startLength = 0;
	//move along the array until we find a '*' or end of string
	while (*input != '*' && *input != '\0')
	{
		input++;
	}
	//if we have been stopped by an '*' skip ahead one
	if (*input == '*')
	{
		hasAsterix = true;
		input++;
	}
	//copy the remaing part of the string to the new string
	//if we have already reaced the end of the string nothing happens here
	while (*input != '\0')
	{	
		*output = *input;
		input++;
		output++;
	}
	//if we were stoped by an '*' earlier add it now and advance by one
	if (hasAsterix)
	{
		*output = '*';
		output++;
	}
	//copy the first part of the string to the end of the new string
	input = inputStart;
	while (*input != '*' && *input != '\0')
	{
		*output = *input;
		output++;
		input++;
	}

	*output = '\0';
} 