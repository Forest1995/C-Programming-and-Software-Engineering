#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
void display(int ar[][4], int n);
int compare(int a[][4], int b[][4]);
int input(void);
int main()
{
	int j, k, t, a, b, c, d;                              /*declare variables*/
	int m = 0, f = 0;
	int array1[16]; int array2[4][4]; int array3[4][4];   /*declare three 2D array*/
	srand(time(0));                                       /*use function srand to generate random numbers */
	for (int i = 0; i < 8; i++) {                         /*use for loop to generate array*/
		array1[i] = rand() % 74 + 48;                     /*%74+48 indicates that the random number must be from 48-121*/
		array1[8 + i] = array1[i];
	}
	for (int i = 0; i < 16; i++) {                        /*use for loop to generate array*/   
		j = rand() % 16;                                  /*%16 indicates that the random number must be from 0-15*/
		k = array1[i];
		array1[i] = array1[j];
		array1[j] = k;
	}
	for (int i = 0; i < 4; i++) {                         /*use for loop to generate array*/
		for (int j = 0; j < 4; j++) {
			array2[i][j] = array1[m];
			m++;
			array3[i][j] = '*';
		}
	}
	display(array2,4);
	Sleep(10000);
	system("cls");
	display(array3, 4);
	for (int i = 1; compare(array2, array3)!=16; i++) {             /*use for loop to circulate and decide when to stop*/
		do {
			f++;
			printf("choose your first card\n");
			printf("row:");
			a = input();
			printf("column:");
			b = input();
			printf("choose your second card\n");
			printf("row:");
			c = input();
			printf("column:");
			d = input();
		} while (a == c&b == d);
		    system("cls");
			array3[a - 1][b - 1] = array2[a - 1][b - 1];
			array3[c - 1][d - 1] = array2[c - 1][d - 1];
			display(array3, 4);
			Sleep(2000);
			if (array2[a - 1][b - 1] == array2[c - 1][d - 1])
				;
			else
			{
				system("cls");
				array3[a - 1][b - 1] = '*';
				array3[c - 1][d - 1] = '*';
				display(array3, 4);
			}
		}
	
	printf("The total number of guesses is %d", f);
}

void display(int ar[][4], int n)                         /*declare function display*/
{
	for (int i = 0; i < 4; i++) {                        /*use 2 for loops to display the given array*/
		for (int j = 0; j < 4; j++) {
			printf("%5c", ar[i][j]);
		}
		printf("\n");
	}
}
int compare(int a[][4], int b[][4]) {                    /*declare function compare*/
	int m = 0;
	for (int i = 0; i < 4; i++) {                        /*use 2 for loops to compare the two given arrays*/
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == b[i][j])
				m++;
			else
				m = 0;
		}
	}return m;
}
int input(void) {                                       /*declare function input*/
	int a;
	char c;
	while (1) {
		if (scanf("%d", &a) == 0)                       /*the correct return value of scanf should be 1*/
		{
			scanf("%c", &c);
			if (c == 'q')
				exit(0);
			else
				printf("wrong input,please enter an integer:");
		}
		else
		{
			return a;
			break;
		}
	}
}