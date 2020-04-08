#include <stdio.h>
#include <time.h>
#include <string.h>

#define SIZE 4
void enter(int*);
void encrypt(int*);
void check(int*, int*, struct code_counter count);
void decrypt(int*);
void quit();

struct code_counter
{
	int correct_code;
	int wrong_code;
};

void checker(struct code_counter count);



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
		printf("##########################\n");
		printf("  Security Authenticator\n");
		printf("##########################\n");
		printf("\n\n1. Enter a code or generate random numbers\n");
		printf("2. Encrypt the code\n");
		printf("3. Compare the code with the authorised access code\n");
		printf("4. Decrypt code\n");
		printf("5. How many times the code was entered correclty or incorrectly\n");
		printf("6. Exit program\n\n");

		printf("Enter number: ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				option_1++;
				menu = 0;
				enter(&enter_code);
				break;

			case 2:
				if (option_1 > 0)
				{
					if (menu == 0)
					{
						menu++;
						encrypt(&enter_code);
						break;
					}
					else
					{
						system("cls");
						printf("\nYou can't encrpyt an encrypted code\n\n");
						break;
					}
				}
				else
				{
				system("cls");
				printf("\nYou have to enter a code first\n\n");
				break;
				}


			case 3:
				system("cls");
				if (menu == 1)
				{
					check(&enter_code, &access_code, count);
					break;
				}
				else
				{
					system("cls");
					printf("\nOnly encrypted codes can be compared\n\n");
					break;
				}

			case 4:
				if (menu == 1)
				{
					decrypt(&enter_code);
					menu--;
					break;
				}
				else
				{
					system("cls");
					printf("\nYou can only decrypt if the code in encyrpted\n\n");
					break;
				}

			case 5:
				checker(count);
				break;

			case 6:
				quit();
				break;

			default:
				printf("\nInvalid\n\n");
		}

	} //End do
	while (option != 6);
	{
		return 0;
	} //End while

	
} //End main()



void enter(int* arr)
{
	int option_enter;
	int i;

	srand(time(NULL));

	do
	{
		printf("\n\n1. Enter your own numbers\n");
		printf("2. Enter random generatered number\n");
		printf("3. Back\n\n");

		printf("Enter number: ");
		scanf("%d", &option_enter);

		if (option_enter == 1)
		{
			printf("Enter you 4 numbers\n");
			for (i = 0; i < SIZE; i++)
			{
				scanf("%d", &*(arr + i));
				if (*(arr + i) > -1 && *(arr + i) < 10)
				{
				}
				else
				{
					printf("You eneterd an invalid number\n");
					i--;
				}
			} //End for
		} //End if

		if (option_enter == 2)
		{
			for (i = 0; i < SIZE; i++)
			{
				*(arr + i) = rand() % 10;
				printf("%d", *(arr + i));
			} //End for
		} //End if

	} while (option_enter != 3);
	{
		printf("\n\n");
		system("cls");
		return;
	} //End while
} //End enter()



void encrypt(int* arr)
{
	int temp, i;

	for (i = 0; i < 2; i++)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + i + 2);
		*(arr + i + 2) = temp;

		*(arr + i) = *(arr + i) + 1;
		*(arr + i + 2) = *(arr + i + 2) + 1;
	} //End for

	for (i = 0; i < SIZE; i++)
	{
		if (*(arr + i) == 10)
		{
			*(arr + i) = 0;
		}
	}

	system("cls");
	printf("\nCode encrypted\n\n");
} //End encrypt()


void check(int* arr, int* code, struct code_counter count)
{

	if (strcmp(arr, code) == 0)
	{
		printf("\nCorrect code entered\n\n");
		
	}
	else
	{
		printf("\nWrong code entered\n\n");
		count.wrong_code++;
	}


}



void decrypt(int* arr)
{
	int temp, i;

	for (i = 0; i < 2; i++)
	{
		*(arr + i) = *(arr + i) - 1;
		*(arr + i + 2) = *(arr + i + 2) - 1;

		temp = *(arr + i);
		*(arr + i) = *(arr + i + 2);
		*(arr + i + 2) = temp;
	} //End for

	for (i = 0; i < SIZE; i++)
	{
		if (*(arr + i) == -1)
		{
			*(arr + i) = 9;
		}
	}

	system("cls");
	printf("\nCode Decrypted\n\n");
}

void checker(struct code_counter count)
{
	printf("You have entered the code correctly %d time(s)\n\n", count.correct_code);
	printf("You have entered the code incorrectly %d time(s)\n\n", count.wrong_code);
}

void quit()
{
	int answer;

	printf("\nAre you sure?\n\n");
	scanf("%d", &answer);

	if (answer == 1)
	{

	}
	if (answer == 0)
	{
		return;
	}
	return;
}

/*
!!Struct
Perfect when exitting
*/