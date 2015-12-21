/*
*	Lab	: 3
*	Exercise: 2
*	Student	: Tom Anderson
*	Number	: C00174844
*	Date	: 10/11/2015
*
*
*/
#include <iostream>


using namespace std;

void getString( char *);
void getSurname(char * fullName, char * surname);

int main()
{
	char fullName[1024];
	char surname[1024];
	cout << "What is your full name?" << endl;
	getString(fullName);
	cout << "Full name - " << fullName << endl;
	getSurname(fullName, surname);
	cout << "Surname - " << surname << endl;
	system("pause");
	return 0;
}

	//method the put keybord input inta a char array passed as a pointer
void getString( char * arrayStart)
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


	//method to scan one char array (fullName) and put everything after the first space into another char array (surname)
void getSurname(char * fullName, char * surname)
{
	//move along the array untill we find a space or terminating character
	while (*fullName != ' ' && * fullName != '\0')
	{
		fullName++;
	}
	//copy the contents of the fullname array into the surname array until we find a terminating character
	while (* fullName != '\0')
	{
		* surname = * fullName;
		surname++;
		fullName++;		
	}
	*surname = '\0';
}
