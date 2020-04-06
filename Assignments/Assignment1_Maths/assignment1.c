/*

Assignment #1

Program that will ask the user matimatical questions and after completing the quiz will
then also display how much questions the user got right and wrong

The program will display a simple menu, which will contain an option to end the program
*/
#include <stdio.h>

int main()
{
	int option;
	int questions = 0;
	int i;
	int num1;
	int num2;
	int answer;
	int checker;
	int correct = 0;
	int incorrect = 0;

	//This will continuously display the menu and run the program until the user selects option 4
	do
	{
		//Displays the menu
		printf("\nThe Mathematics Quiz Game\n\n");
		printf("Chose your selection\n\n");
		printf("1. Enter the number of questions to be asked for this round of the quiz\n");
		printf("2. Start quiz\n");
		printf("3. Display the number of questions that were answered correctly and incorrectly for this round\n");
		printf("4. Exit Program\n");

		scanf("%d", &option);

		//If the user choses the play the quiz with a selected number of questions
		if (option == 1)
		{
			//Asks the user how much questions they want to be asked
			printf("\nHow many questions do you want to be asked? Must be between 1 and 5\n");

			scanf("%d", &questions);

			//Switch statement to see if the correct numbers were entered
			switch (questions)
			{
				case 1:
					printf("You will be asked %d question\n", questions);
					break;
				case 2:
					printf("You will be asked %d questions\n", questions);
					break;
				case 3:
					printf("You will be asked %d questions\n", questions);
					break;
				case 4:
					printf("You will be asked %d questions\n", questions);
					break;
				case 5:
					printf("You will be asked %d questions\n", questions);
					break;
				default:
				{
					printf("Invalid number or character\n");
				} //End default
			} //End swicth

		} //End if (option = 1)

		if (option == 2)
		{
			//If the user goes straight to option #2 without going to option #1 first
			if (questions == 0)
			{
				printf("\nYou need to enter how much questions you want to be asked\n");
			} //End if
			else
			{
				//Everytime you press option #2, the correct and incorrect counter resets
				correct = 0;
				incorrect = 0;

				//
				for (i = 0; i < questions; i++)
				{
					//Randomise the number each time between 1 and 20 and asks for the answer
					num1 = rand() % 30;
					num2 = rand() % 30;

					printf("\n%d + %d = ", num1, num2);
					checker = num1 + num2;

					scanf("%d", &answer);

					//Sees if the answer entered is correct
					if (answer == (num1 + num2))
					{
						printf("\nYou entered: %d. Thats the correct answer\n", answer);
						correct = correct + 1;
					} //End if
					else
					{
						printf("\nYou entered: %d. Thats wrong. The correct answer is %d\n", answer, checker);
						incorrect = incorrect + 1;
					} //End else
				} //End for
			}//End else
		}// End if (option = 2)

		if (option == 3)
		{
			if (correct == 0 && incorrect == 0)
			{
				printf("\nYou need to start the quiz before you can see your results\n");
			} //End if
			else
			{
				//Displays how much you answered correctly and incorrectly
				printf("\nYou have answered %d question(s) correctly", correct);
				printf("\nYou have answered %d question(s) incorrectly\n", incorrect);
			} //End else
		}// End if (option = 3)

		if (option == 4)
		{
			printf("\nThe Program Ended. Please Close the Program");
		}// End if (option = 4)
	} //End do
	while (option != 4);
	
	
	return 0;
} //End main()