/*

* Author: Toby Hilliard, thilliard2019@my.fit.edu

* Course: CSE 1001, Section 01 Fall 2019

* Project: ordinal.c

*/
#include <stdio.h>

int ordinals(int a);
int summation(int a[], int size);

int main (void)

{
	int temp = 0, sumtotal = 0, escape = 0;
	
	printf("Welcome to the ordinal numbers simulator!\nEnter any positive integer (between 0 and 65535) to begin, or enter a negative integer to exit.\n\n");
	do
	{
		printf("Enter an integer: ");
		scanf("%d", &temp);
		
		if(temp>65535)
			printf("Error - Value not recognized. Please try again.\n");
		else if(temp<0)
		{
			escape = 1;
		}
		else
		{
			ordinals(temp);
			sumtotal += temp;
		}
	}while(escape!=1);
	printf("The total of all the numbers you entered was %d. Thanks for playing!", sumtotal);
	return 0;
}

int ordinals(int a)
{
	int ordinal;
	for (int i=0; i<=a; i++)
	{
		ordinal = a - (a - i);
		
		if ( (ordinal % 10 == 1) && ( (ordinal/10) % 10 != 1 ) || (ordinal % 10 == 2) && ( (ordinal/2) != 6 ) || (ordinal % 10 == 3) && ( (ordinal/2 != 6 ) ) )
		{
			printf("If statement entered.\n");
			if ( (ordinal % 10 == 1) )
			{
				printf("%dst Value\n", ordinal);
			}
			else if ( (ordinal % 10 == 2) )
			{
				printf("%dnd Value\n", ordinal);
			}
			else if ( (ordinal % 10 == 3) )
			{
				printf("%drd Value\n", ordinal);
			}				
		}
		else
		{
			printf("%dth Value\n", ordinal);
		}	
	}
	return 0;
}