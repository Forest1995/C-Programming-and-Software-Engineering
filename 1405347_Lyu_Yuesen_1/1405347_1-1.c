#include<stdio.h>/*include information about standard library stdio.h*/
main()
{
	char name[50], student_id_number[50]; /*declare two variables of the type of char namely name and student_id_number*/
	printf("Enter your name:\n");  /*ask user to input a name*/
	gets(name);                    /*store the value into variable name*/
	printf("Enter your student ID number :\n");/*ask user to input a student ID number*/
	gets(student_id_number);       /*store the value into variable student_id_number*/          
	printf("Your name is:");       /*display the name */
	puts(name);
	printf("Your student ID number is:");/*display the student id number*/
	puts(student_id_number);
}