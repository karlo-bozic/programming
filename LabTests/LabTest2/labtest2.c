/*
Program that contains the array called barack
It copies the content from barack and pastes it into an another array called michelle.
It replaces all the empty elements in the michelle arrray with underscore.
Displays the contents of the michelle array to the standard output (screen)
This program uses pointer notation only

Author: Karlo Bozic

Date: 02/12/2019

Compiler: Visual Studio 2019
*/
#include <stdio.h>
#define SIZE 10
int main()
{
	char barack[] = { 'Y', 'E','S',' ' , 'W','E', ' ','C', 'A','N' };
	char michelle[] = { ' ' };
	int i;

	//part 1
	//Copy the first array into the second array
	for (i = 0; i < SIZE; i++)
	{	
		//Places whatever is in the barack array into the michelle array in the same element
		*(michelle + i) = *(barack + i);
	} //End for

	//part 2
	//Replaces the blank with underscores
	for (i = 0; i < SIZE; i++)
	{
		//If the element contains a space. It overrides the space and places an underscore
		if (*(michelle + i) == ' ')
		{
			*(michelle + i) = '_';
		} //End if
	} //End for

	//part 3
	//Displays the michelle array
	for (i = 0; i < SIZE; i++)
	{
		printf("%c", *(michelle + i));
	} //End for

	return 0;
} //End main()