#include<stdio.h> /*include information about standard library stdio.h*/
#define Inches_per_meter 39.37
#define Inches_per_foot 12
main()
{
	double meters, inches;      /*declare two variables of the type of doubke namely meters and inches */
	int feet, inch;             /*declare two variables of the type of int namely feet and inch*/
	printf("Enter your height in meters:"); /*ask user to input a number representing the height*/
	scanf_s("%lf",&meters);     /*store the value into variable meters*/
	inches = Inches_per_meter * meters; /*compute the inches according to the provided formula*/
	feet = inches / Inches_per_foot;    /*compute the feet according to the provided formula*/
	inch = inches - Inches_per_foot * feet + 0.5; /*compute the inche according to the provided formula*/
	printf("That equals to %d feet and %d inches\n", feet,inch);/*display the height in feet*/
}