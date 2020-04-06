/* This program uses the Fibonacci series to display the number of terms on the screen
	Author: Karlo Bozic
	Date: 21/10/2019
*/
#include <stdio.h>
int main()
{
	int term;
	int num;
	int i;
	int num1 = 0;
	int num2 = 1;
	int num3;
	int answer;

	//Start the program or not
	printf("The Fibonacci series program\n\n");
	printf("Enter your selection\n");
	printf("1. Start the program\n");
	printf("2. End program\n");

	//Scans for the answer
	scanf("%d", &answer);

	if (answer == 1)
	{

		//Asks the number for the term
		printf("Enter the number of terms you wish to display\n");

		//Reads the entered number
		scanf("%d", &term);

		//If the first term was asked
		if (term == 1)
		{
			printf("0");
		} //End if
		//If the second term was asked
		if (term == 2)
		{
			printf("0\n1");
		} //End if
		//The maths to find the other terms greater than the 2nd term 
		else
		{
			printf("%d\n%d\n", num1, num2);
			for (i = 0; i + 2 < term; i++)
			{
				//Adds the numbers together
				num3 = num1 + num2;
				printf("%d\n", num3);

				//Puts num3 in the smallest out of num1 or num2
				if (num1 < num2)
				{
					num1 = num3;
				}
				else
				{
					num2 = num3;
				}

			} //End for
		} //End else

	}//End if

	if (answer == 2)
	{
		printf("Please close the program\n");
	} //End if

	return 0;
} //End main()