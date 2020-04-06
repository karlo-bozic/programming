/*  This program asks you if you want to change Euro to Dollars or Dollars to Euro.
    This program uses function in the conversion. You are asked to input 3 amounts and
    they are passed to the function. In the function they are displayed and calculated 
    to the other currency. The average is also calculted and passed to main(). The avg is 
    printed from main()
   Date: 20/02/2020
   Author: Karlo Bozic
   Compiler: Visual Studio 2019
*/
#include <stdio.h>
#define SIZE 3
float change_to_Euro(float[]);
float change_to_Dollar(float[]);


int main()
{
    int options;
    float Euro[SIZE], Dollar[SIZE];
    int i;
    char answer;
    float Dollaravg, Euroavg;

    do
    {
        //Displays the menu
        printf("\n\nChoose a currency\n\n");
        printf("1. Change Euro to Dollars\n");
        printf("2. Change Dollars to Euros\n");
        printf("3. Exit\n");

        scanf("%d", &options);

        //If the user chooses Euro to Dollars
        if (options == 1)
        {
            //Asks the user for three amounts
            printf("Enter 3 amounts in Euros\n");

            //Input the currency 
            for (i = 0; i < SIZE; i++)
            {
                scanf("%f", &Euro[i]);
            } //End for

            //call function
            change_to_Dollar(Euro);

        } //End if (options1)

        if (options == 2)
        {
            //Asks the user for three amounts
            printf("Enter 3 amounts in Dollars\n");

            //Input currency
            for (i = 0; i < SIZE; i++)
            {
                scanf("%f", &Dollar[i]);
            } //End for

            //calls the function
            change_to_Euro(Dollar);


            //diplays the average
            printf("The average is %f", Euroavg);

        } //End if (option2)

        if (options == 3)
        {
            printf("Are you sure you want to exit?\n");

            scanf("%c", &answer);

            if (answer == ('Y'))
            {
                printf("Please close the program");
            } //End if

            if (answer == ('N'))
            {

            } //End if


            //diplays the average
            printf("The average is %f", Dollaravg);

        } //End if (option3)
        
    } //End do
    while (options != 3);

    return 0;
} //End main()

float change_to_Euro(float arr[])
{
    float Euro[SIZE], E_avg;
    int i;

    printf("\n\nThe Dollar amount you entered are:\n");

    for (i = 0; i < SIZE; i++)
    {
        //Displays the Dollars
        printf("%.2f ", arr[i]);

        //clauclates to Euro
        Euro[i] = ((float)arr[i] / 1.19);
    } //End for

    printf("\n\nThe Euro values are:\n");
    for (i = 0; i < SIZE; i++)
    {
        //Displays the Euro
        printf("%.2f ", Euro[i]);
    } //End for
    
    E_avg = Euro[i] / SIZE;

    //returns the avg
    return E_avg;
} //End

float change_to_Dollar(float arr[])
{
    float Dollar[SIZE], D_avg;
    int i;

    printf("\n\nThe Euro amount you entered are:\n");

    for (i = 0; i < SIZE; i++)
    {
        //Displays the Dollars
        printf("%.2f ", arr[i]);

        //clauclates to Euro
        Dollar[i] = ((float)arr[i] / 0.84);
    } //End for

    printf("\n\nThe Euro values are:\n");
    for (i = 0; i < SIZE; i++)
    {
        //Displays the Euro
        printf("%.2f ", Dollar[i]);
    } //End for

    //calculates avg
    D_avg = Dollar[i] / SIZE;

    //returns the avg
    return D_avg;
} //End