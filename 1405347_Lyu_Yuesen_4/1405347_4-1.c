#include<stdio.h>                                                        /* include information about standard library stdio.h*/
int login(int array[][3],int n);
void menu(int price);
void search(int  price);
void withdraw(int price);
void deposit(int price);
int input(void);
main() {
	int array[5][3] = { 1,111,1000,2,222,2000,3,333,3000,4,444,4000,5,555,5000 }; /*Declare  a 2Darray*/
	int price;
	price = login(array, 5);                                                      /*give the 2Darray to function login*/
	menu(price);                                                                  /*give the value of price to function menu*/
}
void menu(int price){                                                            /*declare a function menu*/
	int a;
	printf("|       1.search      |\n");
	printf("|       2.withdraw    |\n");
	printf("|       3.deposit     |\n");
	printf("|       4.quit        |\n");
	a = input();
	switch (a) {                                                         /* use switch statement for users to selsect options*/
	case 1:search(price); break;
	case 2:withdraw(price); break;
	case 3:deposit(price); break;
	case 4: break;
	default:printf("illegal input\n"); menu(price);
	}
}
int login(int array[][3],int n) {                                               /*declare a function login*/
	int a, b, k,j = 1, i = 0;
	do {                                                                        /*use do while loop for circulation*/
		printf("enter the account name:");
		a = input();
		printf("enter the passcode:"); 
		b = input();
		for (i = 0; i <= 4; i++)                                                
			if ((a == array[i][0])&(b == array[i][1])) {
				j = 0;
				k = array[i][2];
			}
	} while (j == 1);
	printf("login in successfully\n");
	return k;
}

void search(int price)                                                             /*declare a function search*/
{
	int a;
	printf("|Your current account value is£º%d\n", price);
	printf("Please select the following options:\n");
	printf("|       1.return      |\n");
	printf("|       2.quit        |\n");
	a = input();
	switch (a)                                                       /* use switch statement for users to selsect options*/
	{
	case 1: menu(price); break;
	case 2: break;
	default:printf("illegal input\n"); menu(price);
	}
}
void withdraw(int price){                                                            /*declare a function withdraw*/
	int a, b, n;
	printf("Please enter the money you want to withdraw£º\n");
	n = input();
	if (n>price)
	{
		printf("Sorry,your balance is insufficient\n");
		printf("Please select the following options:\n");
		printf("|       1.return      |\n");
		printf("|       2.quit        |\n");
		a = input();
		switch (a)                                          /* use switch statement for users to selsect options*/
		{
		case 1:menu(price); break;
		case 2: break;
		default:printf("illegal input\n"); menu(price);
		}
	}
	else
	{
		printf("Withdraw seccessfully! Your current account value is:%d.\n",price - n);
		printf("Please select the following options:\n");
		printf("|       1.return     |\n");
		printf("|       2.quit    |\n");
		b = input();
		switch (b)                                              /* use switch statement for users to selsect options*/
		{
		case 1:menu(price-n); break;
		case 2: break;
		default:printf("illegal input\n"); menu(price-n); break;
		}
	}

}
void deposit(int price)                                                                  /*declare a function deposit*/
{
	int a, n;
	printf("Please enter the number you want to deposit:");
	n = input();
	while (n<0)
	{
		printf("illegal input,please enter the number again£º\n");
		n = input();
	}
	printf("deposit successfully, your current account value is£º%d.\n",price + n);
	printf("Please select the following options:\n");
	printf("|       1.return    |\n");
	printf("|       2.quit      |\n");
	a = input(); 
	switch (a)                                                 /* use switch statement for users to selsect options*/
	{ 
	case 1:menu(price+n); break;
	case 2: break;
	default:printf("illegal input\n"); menu(price+n); break;
	}
}
int input(void) {                                                                     /*declare a function input*/
	int a;
	char c;
	while (1) {
		if (scanf("%d", &a) == 0)                                  /*the correct return value of scanf should be 1*/
		{
			printf("wrong input,please enter an integer:");
			scanf("%c", &c);
		}
		else
		{
			return a;
			break;
		}
	}
}