#include <stdio.h>                           /* include information about standard library stdio.h*/
void rank(int x, int y, int z);
float mode_average(float x, float y, float z);
main() {                                     /*define a function named main*/
		float a,b,c,m;                       /* declare four variables*/
		printf("enter score1:");             /* ask user to input three numbers and store them as a,b,c*/
		scanf("%f", &a);
		printf("enter score2:");
		scanf("%f", &b);
		printf("enter score3:");
		scanf("%f", &c);
		rank(a, b, c);                      /*use rank function to rank the three numbers*/
		m = mode_average(a, b, c);          /*use mode_average function to compute the mode/aveerage value and return it to m*/
		printf("Mode/Average values %.3f\n", m);/*display the mode/average value*/
		if (m < 4)                          /*use if statement to decide which grade the mode/average number is and display the result*/
			printf("Grade: fail");
		if (m >= 4 & m < 5)
			printf("Grade: Third");
		if (m >= 5 & m < 6)
			printf("Grade: Lower Second");
		if (m >= 6 & m < 7)
			printf("Grade: Upper Second");
		if (m >= 7 & m < 10)
			printf("Grade: First");
	}
void rank(int x, int y, int z)    /* define a function named rank*/
{
	int t;                        /* declare one variable*/
	if (x > y) {                  /* use if statement to change the order of three numbers */
		t = x;
		x = y;
		y = t;
	}
	if (x > z) {
		t = x;
		x = z;
		z = t;
	}
	if (y > z) {
		t = y;
		y = z;
		z = t;
	}
	printf("Rank values:%d%3d%3d\n", x, y, z);
}
float mode_average(float x, float y, float z) {    /* define a function named mode_average*/
	float n;                                       /* declare one variable*/
	if (x == y)                                    /* use if else statement to compute the mode/average value*/
		n = x;
	else if (x == z)
		n = x;
	else if (y == z)
		n = y;
	else
		n = (x + y + z) / 3;
	return n;                                      /* return the value to the main function*/
}