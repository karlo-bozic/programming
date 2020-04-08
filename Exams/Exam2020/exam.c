/*  This program is a Security Authenticator.

	It will ask the user to input a code, this will be encrypted and compared with the access_code (4523). 
	The code will be decrypted back to its original code and it will display how many times you entered the code correctly
	Each step must be made into its own function
	The variables in the function must be passed by reference and had to use pointer notation only.
	
	Function:
	1. This function will ask the user whether you want to input your own code or to get a random generated number. 
	2. This function will encrypt the code with the algorithm given in the question.
	3. The encrypted code will be compared with the access_code in order to see if the user entered the correct code. 
	4. The encrypted code will be decrypted back to the original code that the user entered in function 1 using the given algorithm.
	5. This will display how many times the user entered the code correctly or incorrectly.
	6. The user will be asked if they want to exit the program.

	Author: Karlo Bozic
	Date: 03/04/2020 (Updated 08/04/2020)
	Compiler: Visual Studio 2019
*/
#include <stdio.h>
#include <time.h>
#include <string.h>
#define SIZE 4

// function signature
void enter(int*);
void encrypt(int*);
void check(int*, int*, struct code_counter count);
void decrypt(int*);
void checker(struct code_counter count);
void quit();

struct code_counter
{
	int correct_code;
	int wrong_code;
};




int main()
{
	int enter_code[SIZE];
	struct code_counter count;
	count.correct_code = 0;
	count.wrong_code = 0;
	int option;
	char answer;
	int menu = 0, option_1 =0;
	int access_code[SIZE] = { 4, 5, 2, 3 };

	do
	{
		// menu options
		printf("##########################\n");
		printf("  Security Authenticator\n");
		printf("##########################\n");
		printf("\n\n1. Enter a code or generate random numbers\n");
		printf("2. Encrypt the code\n");
		printf("3. Compare the code with the authorised access code\n");
		printf("4. Decrypt code\n");
		printf("5. How many times the code was entered correclty or incorrectly\n");
		printf("6. Exit program\n\n");

		// enter your option
		printf("Enter number: ");
		scanf("%d", &option);

		// switch case used to go into a function the user chooses
		switch (option)
		{
			case 1:
				option_1++;
				menu = 0;
				// calls the function enter
				enter(&enter_code);
				break;

			case 2:
				if (option_1 > 0)
				{
					if (menu == 0)
					{
						menu++;
						// calls the function encrypt
						encrypt(&enter_code);
						break;
					} //End else
					else
					{
						// clears display
						system("cls");
						printf("\nYou can't encrpyt an encrypted code\n\n");
						break;
					} //End else
				} //End if
				else
				{
					// clears display
					system("cls");
					printf("\nYou have to enter a code first\n\n");
					break;
				} //End else


			case 3:
				system("cls");
				if (menu == 1)
				{
					// calls the function check
					check(&enter_code, &access_code, count);
					break;
				} //End if
				else
				{
					// clears display
					system("cls");
					printf("\nOnly encrypted codes can be compared\n\n");
					break;
				} //End else

			case 4:
				if (menu == 1)
				{
					// calls the function decrypt
					decrypt(&enter_code);
					menu--;
					break;
				} //End if
				else
				{
					// clears display
					system("cls");
					printf("\nYou can only decrypt if the code in encyrpted\n\n");
					break;
				} //End else

			case 5:
				// calls the function display
				checker(count);
				break;

			case 6:
				// calls the function quit
				quit();
				break;

			default:
				printf("\nInvalid\n\n");
		} //End switch

	} //End do
	while (option != 6);
	{
		return 0;
	} //End while

	
} //End main()


// 1. implement enter()
void enter(int* arr)
{
	int option_enter;
	int i;

	// uses the computer time to generate random numbers every time
	srand(time(NULL));

	do
	{
		// menu options
		printf("\n\n1. Enter your own numbers\n");
		printf("2. Enter random generatered number\n");
		printf("3. Back\n\n");

		// enter your option
		printf("Enter number: ");
		scanf("%d", &option_enter);

		// if the user chooses option 1
		if (option_enter == 1)
		{
			printf("Enter you 4 numbers\n");
			for (i = 0; i < SIZE; i++)
			{
				scanf("%d", &*(arr + i));
				if (*(arr + i) > -1 && *(arr + i) < 10)
				{
				} //End if
				else
				{
					// if the user inputs a number less than 0 and greater than 9
					printf("You eneterd an invalid number\n");
					i--;
				} //End else
			} //End for
		} //End if

		// if the user chooses option 2
		if (option_enter == 2)
		{
			for (i = 0; i < SIZE; i++)
			{
				// inputs random numbers for the code between 0 and 9
				*(arr + i) = rand() % 10;
				printf("%d", *(arr + i));
			} //End for
		} //End if

	} //End do
	while (option_enter != 3);
	{
		printf("\n\n");
		// clears the display
		system("cls");
		return;
	} //End while
} //End enter()


// 2. implement encrypt()
void encrypt(int* arr)
{
	int temp, i;

	for (i = 0; i < 2; i++)
	{
		// switches the numbers according to the algorithm given
		temp = *(arr + i);
		*(arr + i) = *(arr + i + 2);
		*(arr + i + 2) = temp;
		
		// adds one to all numbers
		*(arr + i) = *(arr + i) + 1;
		*(arr + i + 2) = *(arr + i + 2) + 1;
	} //End for

	// checks if the number is 10 and replaces it with 0
	for (i = 0; i < SIZE; i++)
	{
		if (*(arr + i) == 10)
		{
			*(arr + i) = 0;
		} //End if
	} //End for

	// clears the display
	system("cls");
	printf("\nCode encrypted\n\n");
} //End encrypt()



// 3. implement check()
void check(int* arr, int* code, struct code_counter count)
{
	// uses strcmp to compare the two codes. If they are similar strcmp returns 0.
	if (strcmp(arr, code) == 0)
	{
		printf("\nCorrect code entered\n\n");
	} //End if
	else
	{
		printf("\nWrong code entered\n\n");
	} //End else
} //End check()


// 4. implement decrypt()
void decrypt(int* arr)
{
	int temp, i;

	for (i = 0; i < 2; i++)
	{
		// takes 1 away from all the numbers
		*(arr + i) = *(arr + i) - 1;
		*(arr + i + 2) = *(arr + i + 2) - 1;

		// switches the number according to the algorithm given
		temp = *(arr + i);
		*(arr + i) = *(arr + i + 2);
		*(arr + i + 2) = temp;
	} //End for

	// checks if the number is -1 and replaces it with 9
	for (i = 0; i < SIZE; i++)
	{
		if (*(arr + i) == -1)
		{
			*(arr + i) = 9;
		} //End if
	} //End for

	// clears display
	system("cls");
	printf("\nCode Decrypted\n\n");
} //End decrypt()



// 5. implement checker()
void checker(struct code_counter count)
{
	// displays how many times the code was enetered correctly and incorrectly
	printf("You have entered the code correctly %d time(s)\n\n", count.correct_code);
	printf("You have entered the code incorrectly %d time(s)\n\n", count.wrong_code);
} //End checker


// 6. implement quit()
void quit()
{
	int answer;

	// askes the user to leave or stay
	printf("\nAre you sure?\n\n");
	scanf("%d", &answer);

	// if user chooses to leave or to stay
	if (answer == 1)
	{

	} //End if
	if (answer == 0)
	{
		return;
	} //End if
	return;
} //End quit()

/*
!!Struct
Perfect when exitting
*/