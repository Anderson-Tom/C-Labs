/*
*	Lab	: 3
*	Exercise: 3
*	Student	: Tom Anderson
*	Number	: C00174844
*	Date	: 10/11/2015
*
*
*/
#include <iostream>

using namespace std;

void getString(char *);
void getForeName(char * fullName, char * foreName);

int main()
{
	char fullName[1024];
	char foreName[1024];
	cout << "What is your full name?" << endl;
	getString(fullName);
	cout << "Full name - " << fullName << endl;
	getForeName(fullName, foreName);
	cout << "Forename - " << foreName << endl;
	system("pause");
	return 0;
}

	//method the put keybord input inta a char array passed as a pointer
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


	//method to scan one char array (fullName) and put everything before he first space into another char array (foreName)
void getForeName(char * fullName, char * foreName)
{
	//move along the array untill we find a space or terminating character
	//and copy the characters to the foreName array
	while (*fullName != ' ' && * fullName != '\0')
	{
		*foreName = *fullName;
		foreName++;
		fullName++;
	}
	//add a terminating character
	*foreName = '\0';

}
