/* 
	This program is a lottery game. Each step to this program must to made is their own seprate function and had to use pointer notation.
	Once the program is started, it displays a menu in which the user can choose where to go. If the user hasn't entered the numbers first in
	option 1, the program will not allow you to go into the other options in the menu.

	Function:
	1. This function asks the user to input 6 lotto numbers and they must be between 1-42. There are multiple error checking in thisfunction which looks 
	   for if the number entered is between 1-42 and if they enter anything thats not an int
	2. This function displays the numbers entered to the user on the standard output (screen).
	3. This program using bubble sort in order to sort the array from smallest to largest. It also displays the sorted array to the standard output (screen).
	4. This function displays the possible winnings from the lottery and then compares the winning numbers to the users numbers. It also displays what the user actaully won.
	5. This program uses the histogram method to find the frequency of each number that the user entered.

	The program has an exit option also.

	Author: Karlo Bozic
	Date: 21/02/2020 ( Updated 02/03/2020 )
*/
#include <stdio.h>
#define SIZE 6
#define FREQ 43

// function signature
int num(int*, int);
void dis(int*);
void sort(int*);
void compare(int*);
void freq(int*);
void check(void);

int main()
{
	int lotto[SIZE];
	int option;
	int menu = 0;
	int error;


	do
	{
		// menu options
		printf("\n\n######################\n");
		printf("     Lottery Game\n");
		printf("######################\n\n");
		printf("Choose your selection\n\n");
		printf("1. Enter 6 lotto numbers bewtween 1 to 42\n");
		printf("2. Display the 6 lotto numbers that you entered\n");
		printf("3. Sort the numbers from smallest to largest\n");
		printf("4. Compare your lotto numbers with the winning numbers\n");
		printf("5. Display the frequency of the numbers entered\n");
		printf("6. Exit the program\n\n");

		// enter your option
		error = scanf("%d", &option);

		if(error == 0)
		{
					fputs ("Non numeric value entered\n", stderr); 

					// calls to the function check
                    check();
		}

		// if user chooses option 1
		if (option == 1)
		{
			// adds one to menu. This makes sure that the user can't enter other options without entering part 1. first
			menu++;
			
			// calls to the function num
			menu = num(lotto, menu);
		} //End if

		//if user chooses option 2
		if (option == 2)
		{
			// checks if option 1 was pressed
			if (menu == 0)
			{
				printf("\nYou need the enter your lotto numbers in order to see them\n\n");
			} //End if
			else
			{
				// calls the function dis
				dis(lotto);
			} //End else
		} //End if

		//if user chooses option 3
		if (option == 3)
		{
			// checks if option 1 was pressed
			if (menu == 0)
			{
				printf("\nYou need the enter your lotto numbers in order to see them\n\n");
			} //End if
			else
			{
				// calls the function sort
				sort(lotto);
			}
		} //End if (option3)

		if (option == 4)
		{
			// checks if option 1 was pressed
			if (menu == 0)
			{
				printf("\nYou need the enter your lotto numbers in order to see them\n\n");
			} //End if
			else
			{
				// calls the function compare
				compare(lotto);
			} //End else
		}

		if (option == 5)
		{
			// checks if option 1 was pressed
			if (menu == 0)
			{
				printf("\nYou need the enter your lotto numbers in order to see them\n\n");
			} //End if
			else
			{
				// calls the function freq
				freq(lotto);
			} //End else
		}

	} //End do
	while (option != 6);
	{
		// if they want to exit the program
		printf("\nThanks for Playing\n");
		printf("Please close the program");
	} //End while

	return 0;
} //End main()

// 1. implement num()
int num(int* arr, int menu)
{
	int i, freq[SIZE];
	int j;

	// enter the numbers
	printf("\n1. Enter your lottery numbers:\n");
	for (i = 0; i < SIZE; i++)
	{
		scanf("%d", &*(arr + i));

		if (*(arr + i) > 0 && *(arr + i ) < 43)
		{
			for (j = 0; j < i; j++)
			{
				if (*(arr + i) == *(arr + j))
				{
					printf("You Enter the same number\n");
					return 0;
				} //End if
			} //End for
		} //End if
		else
		{
			printf("You entered another less than 1 and greater than 42\n");
			printf("Enter the lotto numbers again\n\n");
			return 0;
		} //End else
	} //End for1


	return menu;
} //End num()


// 2. implement dis()
void dis(int* display)
{
	int i;

	// displays the numbers
	printf("\n2. You entered:\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", *(display + i));
	} //End for
} //End dis()


// 3. implement sort()
void sort(int* arr)
{
	int i,j,temp;

	printf("\n3. The sorted array is:\n");

	// bubble sort
	for ( i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < (SIZE - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			} //End if
		} //End for
	} //End for

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", *(arr + i));
	} //End for
} //End sort()

// 4. implement compare()
void compare(int* arr)
{
	int win[SIZE] = { 1,3,5,7,9,11 };
	int j, i, same = 0;

	// displays the prizes
	printf("\n4. Lottery Prizes\n\n");
	printf("#############################\n");
	printf("6 Matches = Jackpot\n");
	printf("5 Matches = New Car\n");
	printf("4 Matches = Weekend Away\n");
	printf("3 Matches = Cinema Pass\n");
	printf("2 Matches = Nothing\n");
	printf("1 Matches = Nothing\n");
	printf("0 Matches = Nothing\n");
	printf("#############################\n");

	// checks if the winning numbers are the same with the chosen numbers
	for (j = 0; j < SIZE; j++)
	{
		for (i = 0; i < SIZE; i++)
		{
			if (*(arr + j) == *(win + i))
			{
				same++;
			} //End if
		} //End for
	} //End for

	printf("\nThe Winning Numbers are:\n");
	printf("1, 3, 5, 7, 9, 11\n");
	printf("\nYou have matched %d numbers\n\n", same);

	// this switch statement displays what the user has won
	switch (same)
	{
		case 0:
			printf("You got nothing`\n");
			break;
		case 1:
			printf("You won nothing\n");
			break;
		case 2:
			printf("You won nothing\n");
			break;
		case 3:
			printf("You won Cinema Passes\n");
			break;
		case 4:
			printf("You won a Weekend Away\n");
			break;
		case 5:
			printf("You won a New Car\n");
			break;
		case 6:
			printf("You got the Jackpot\n");
			break;
		default:
		{

		} //End default
	} //End switch
} //End compare


// 5. implement freq()
void freq(int* arr)
{

	int i, j, count[SIZE] = { 0,0,0,0,0,0 };

	// goes thorugh the numbers from 1 to 42 and sees if the inputted numbers matches.
	for (i = 1; i < FREQ; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (arr[j] == i)
			{
				count[j]++;
			} //End if
		} //End for
	} //End for

	// displays the freq of the numbers 
	for (i = 0; i < SIZE; i++)
	{
		printf("The number %d appeared %d time(s)\n", arr[i], count[i]);
	} //End for

} //End freq


// clears std input 
void check(void)
{
    int c = getchar();

	while (c != '\n' && c != EOF)
	{
		c = getchar();
	} //End while
} //End check