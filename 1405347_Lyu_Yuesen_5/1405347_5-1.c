#include<stdio.h>                                        /* include information about standard library stdio.h*/
void menu(FILE*pfile);                                   /*define a function named menu*/
void add(FILE*pfile);                                    /*define a function named add*/
void search(FILE*pfile);                                 /*define a function named search*/
void sort(FILE*pfile);                                   /*define a function named sort*/
int input1(void);                                        /*define a function named input1*/
int input(void);                                         /*define a function named input*/
void option(FILE*pfile);                                 /*define a function named option*/
struct information {                                     /*define a type of structure named information*/
	char Family_name[20];                                /*declare a character string named Family_name[20]*/
	char Given_name[20];                                 /*declare a character string named Given_name[20]*/
	int student_id;                                      /*declare an integer named student_id */
	char email_address[50];                              /*declare a character named string email_address[50]*/
	int score[6];                                        /*declare an array named score[6]*/
	float average_mark;                                  /*declare a float number named average_mark*/
};
main() {
	FILE *pfile;                                                                     /*declare a file pointer pfile*/
	int a;                                                                           /*declare an integer a*/
	char b[50];                                                                      /*declare a character string b*/
	printf("create a new database(enter 1) or open an existing database(enter 2):"); /* ask user to input an integer number */
	a = input1();                                                                    /*return the value of input1 to a*/
	if (a == 1) {                                                                    
		printf("enter the name of file:");                                           /* ask user to input a file name */
		scanf("%s", b);                                                              /* store the character string into b*/
		pfile = fopen(b, "w+");                                                      /*open file named b with w+ mode*/
		printf("opening %s.txt successfully\n", b);
	}
	if (a == 2) {
		printf("enter the name of the file:");                                       /* ask user to input a file name */
		scanf("%s", b);                                                              /* store the character string into b*/
		pfile = fopen(b, "r");                                                       /*open file named b with r mode*/
		if (pfile == NULL) {                                                         /*Testing for failure of fopen*/
			printf("Failed opening %s.txt", b);    
			exit(1);                                                                 /*exits program*/
		}
		else
		{
			printf("opening %s.txt successfully\n", b);
			if (fclose(pfile) != 0)                                                  /*Testing for failure of fclose*/
				printf("Error closing file\n");
			pfile = fopen(b, "a+");                                                  /*open file named b with a+ mode*/
			if (pfile == NULL) {                                                     /*Testing for failure of fopen*/
				printf("Failed opening %s.txt", b);
				exit(1);
			}
		}
	}
	menu(pfile);                                                        /*enter into function menu*/
}

void menu(FILE*pfile) {                                                 /*declare a function named menu*/
	int a;
	printf("Please select the following options:\n");                   /*ask user to select options*/
	printf("|       1.add         |\n");
	printf("|       2.search      |\n");
	printf("|       3.sort        |\n");
	printf("|       4.quit        |\n");
	a = input();                                                       /*return the value of input1 to a*/
	switch (a) {                                                       /* use switch statement for users to select options*/
	case 1:add(pfile);                                                 /*enter into function add*/
	case 2:search(pfile);                                              /*enter into function search*/
	case 3:sort(pfile);                                                /*enter into function sort*/
	case 4: if (fclose(pfile) != 0)                                                  /*Testing for failure of fclose*/
		printf("Error closing file\n"); exit(0);                                                   /*exits the program */
	default:printf("illegal input\n"); menu(pfile);
	}
}
void add(FILE*pfile) {                                                 /*define a function named add*/
	fseek(pfile, 0, SEEK_END);                                         /*move the file pointer to the end of file*/
	struct information IN;                                             /*declare a struct named IN*/
	getchar();
	printf("Famliy name:");                                            /*get the famliy name*/
	gets(IN.Family_name);
	
	printf("Given name:");                                             /*get the givenname*/
	gets(IN.Given_name);

	printf("Email address:");                                          /*get the email address*/
	gets(IN.email_address);

	printf("Student ID:");                                             /*get the student ID*/
	IN.student_id = input();

	for (int i = 0; i < 6; i++)                                        /*get the 6 scores*/
	{
		printf("score %d:", i + 1);
		IN.score[i]=input();
	}

	printf("Average mark:");                                           /*get the average mark*/
	scanf("%f", &IN.average_mark);
	int b;                                                                
    b=fwrite(&IN, sizeof(struct information), 1, pfile);               /*fwrite returns 1 if it works successfully*/    
	if (b == 1)                                                        /*detect the result of fwrite*/
		printf("adding successfully\n");
	else
		printf("failed adding\n");
	option(pfile);                                                     /*enter into function option*/
}
void search(FILE*pfile) {                                              /*define a function named search*/
	struct information IN[100];                                        /*declare a struct named IN[100]*/
	int a;
	printf("enter the ID:");
	a = input();
	rewind(pfile);                                                        /*move the file pointer to the start of file*/
	for (int i = 0; fread(&IN[i], sizeof(struct information), 1, pfile)!=0; i++) { /*fread returns 1 if it works successfully*/
		if (a == IN[i].student_id) {                                            /*compare the input with existing information*/
			printf("Family name : %s\n", IN[i].Family_name);                                  /*display the information of a student*/
			printf("Given name : %s\n", IN[i].Given_name);
			printf("Email address : %s\n", IN[i].email_address);
			printf("Student ID : %d\n", IN[i].student_id);
			for (int j = 0; j < 6; j++)
			{
				printf("Score %d : %d\n",j+1, IN[i].score[j]);
			}
			printf("Average mark : %.2f\n", IN[i].average_mark);
			option(pfile);                                                 /*enter into function option*/
		}
	}
	printf("not in the database\n");
	option(pfile);                                                        /*enter into function option*/
}
void sort(FILE*pfile) {                                                   /*define a function named sort*/
	rewind(pfile);
	struct information IN[100];
	struct information t;
	int i, j, n;
	for (n = 0; fread(&IN[n], sizeof(struct information), 1, pfile) != 0; n++) {
	}                                       /*fread returns 1 if it works successfully so that it can count the value of n */
	for (i = 0; i<n; i++)                                           /*compare n times*/
	for (j = 1; j<n; j++)                                           /*every time compare j times*/
		for (i = 0; i<j; i++)                                       /*compare with the element behind the IN[i].student_id*/
			if (IN[i].student_id>IN[j].student_id)            
			{
				t = IN[i]; IN[i] = IN[j]; IN[j] = t;
			}                                                       /*exchange the whole structure */
	
	for (i = 0; i < n; i++) {                                       /*use for loop to display the entire database*/
		printf("Family name : %s\n", IN[i].Family_name);                                
		printf("Given name : %s\n", IN[i].Given_name);
		printf("Email address : %s\n", IN[i].email_address);
		printf("Student ID : %d\n", IN[i].student_id);
		for (int j = 0; j < 6; j++)
		{
			printf("Score %d : %d\n", j + 1, IN[i].score[j]);
		}
		printf("Average mark : %.2f\n", IN[i].average_mark);
	}
	option(pfile);                                           /*enter into function option*/
}
int input(void) {                                           /*declare a function named input*/
	int a;
	char c;
	while (1) {
		if (scanf("%d", &a) == 0)                            /*the correct return value of scanf should be 1*/
		{
			printf("wrong input,please enter an integer:");
			scanf("%c", &c);
		}
		else
		{
			return a;                                      /*return the value of a to original function*/
			break;                                         /*jump out of loop*/
		}
	}
}
int input1(void) {                                         /*declare a function named input*/
	int a;
	char c;
	while (1) {
		if (scanf("%d", &a) == 0)                        /*the correct return value of scanf should be 1*/
		{
			printf("wrong input, please enter number 1 or 2 :");
			scanf("%c", &c);
		}
		else if (a != 1 & a != 2)
			printf("wrong input, please enter number 1 or 2:");
		else
		{
			return a;                                    /*return the value of a to original function*/
			break;                                       /*jump out of loop*/
		}
	}
}
void option(FILE*pfile) {                                /*declare a function named option*/
	int a;
	printf("Please select the following options:\n");
	printf("|       1.return      |\n");
	printf("|       2.quit        |\n");
	a = input();                                        /*return the value of input to a*/
	switch (a)                                          /* use switch statement for users to selsect options*/
	{
	case 1: menu(pfile);                                /*enter into function menu*/
	case 2: if (fclose(pfile) != 0)                                                  /*Testing for failure of fclose*/
		printf("Error closing file\n"); exit(0);
	default:printf("illegal input\n"); menu(pfile);
	}
}