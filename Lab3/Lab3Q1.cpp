/*
*	Lab	: 3
*	Exercise: 1
*	Student	: Tom Anderson
*	Number	: C00174844
*	Date	: 10/11/2015
*
*
*/



#include <iostream>

using namespace std;

int main()
{
	int valueArray [] = { 23, 122, 55, 2, 120, 13, 17, 23, 32, 22, 12, 1, 33, 87, 120, 33, 45, 122, 33, 44 };
	const int SEARCHVALUE = 12;
	//create null pointers for the first and last occurances of the value we are searching for
	int * firstInstance = NULL;
	int * lastInstance = NULL;
	//create a pointer to the first item in the array
	int * indexPointer;
	indexPointer = valueArray;
	//iterate 20 times
	for (int index = 0; index < 20; index++)
	{
		//if the value at the address held in the indexPointer is the vale we are looking for??
		if (*indexPointer == SEARCHVALUE)
		{
			//if the pointer to the first instance has not been set to point at anything - is it still null
			if (firstInstance == NULL)
			{	//load it with the address held in indexPointer
				firstInstance = indexPointer;	
			}
			//load the last instance pointer the address held in indexPointer
			lastInstance = indexPointer;		
		}
		//increase the address held in indexpointer by the amount of addresss it takes to hold an int
		indexPointer ++;
	}	
	//check if we have found an instance of our search value
	if (firstInstance != NULL)
	{
		cout << "The index sequence number of the first occurence of " << SEARCHVALUE << " is " << (firstInstance - valueArray + 1) << endl;
		cout << "The index sequence number of the last  occurence of  " << SEARCHVALUE << " is " << (lastInstance - valueArray + 1) << endl;
	}
	else
	{
		cout << "The index sequence number of the first occurence of " << SEARCHVALUE << " is 0 (Not found)"  << endl;
		cout << "The index sequence number  of the last  occurence of  " << SEARCHVALUE << " is 0 (Not found)"  << endl;
	}
		
	system("pause");
	return 0;
}