#include<stdio.h>/*include information about standard library stdio.h*/
main() {
	int number1, number2, x, y;/*declre four variables of the type of int namely number1, number2, x and y*/
	int a = 1, b = 1, answer1 = 0, answer2 = 0;/*declre four variables of the type of int and give them an initial value */
	char z;                   /*declre a variable of the type of char namely z*/
start:
	printf("Enter the first number from 1-100:");/*ask user to input a number */
	scanf("%d", &number1);                       /*store the value into variable number1*/
	system("cls");                               /*clear the screan*/
	printf("Enter the second number from 1-100:");/*ask user to input a number */
	scanf("%d", &number2);                       /*store the value into variable number1*/
	system("cls");                               /*clear the screan*/
	do                                           /*a do while loop*/
	{
		if (answer1 != 1)                        /*the first if statement in the do while loop*/
		{
			printf("Please guess the first number:");
			scanf("%d", &x);
			if (x > number1)
			{
				printf("Your guess was high\n"); a++;
			}
			else
				if (x < number1)
				{
					printf("Your guess was low\n"); a++;
				}
				else
				{
					printf("Your guess was CORRECT\n");
					answer1 = 1;
					printf("The total number of guess was:%d\n", a);
				}
		}
		if (answer2 != 1)                                   /*the second if statement in the do while loop*/
		{
			printf("Please guess the second number:");
			scanf("%d", &y);
			if (y > number2)
			{
				printf("Your guess was high\n"); b++;
			}
			else
				if (y < number2)
				{
					printf("Your guess was low\n"); b++;
				}

				else
				{
					printf("Your guess was CORRECT\n");
					answer2 = 1;
					printf("The total number of guess was:%d\n", b);
				}
		}
	} while (answer1 != 1 || answer2 != 1);         /*the test expression for the loop*/
	printf("Do you want to start again?(Y/N):");    /*ask user whether they want to play again */
	getchar();
	scanf("%c", &z);                                /*store the input into variable z*/
	system("cls");                                  /*clear the screan*/
	if (z == 'Y' || z == 'y')                       /*a if statement*/
	{
		a = 1, b = 1, answer1 = 0, answer2 = 0;     /*give  initial values to the variables again*/
		goto start;                                 /*go back to 'start'*/
	}
	else return 0;
}
		
