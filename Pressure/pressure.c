/*
*Author: Toby Hilliard, thilliard2019@my.fit.edu
*Course: CSE 1001, Section 01 Fall 2019
*Project: pressure.c
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	//Set variables with value of constants.
	
	double pressure_init = 101325 /*Pa*/;
	double temp_lapse_rate = 0.00976 /*K/m*/;
	double temp_init = 288.16 /*Deg K*/;
	double grav = 9.80665 /*m/s^2*/;
	long double mol_air = 0.02896968 /*kg/mol*/;
	long double uni_gas_const = 8.314462618; /*J/(mol*K)*/
	
	//The variables used to calculate the pressure.
	
	double alt_1, alt_2, alt_3, x1, x2, x3, y;
	long double pressure_1, pressure_2, pressure_3;
	double power1, power2, power3;
	
	//Print/Scan statements that ask for and get user input.
	
	printf("Enter the first altitude in meters: ");
	scanf("%lf", &alt_1);
	
	printf("Enter the second altitude in meters: ");
	scanf("%lf", &alt_2);
	
	printf("Enter the third altitude in meters: ");
	scanf("%lf", &alt_3);
	
	//Defines the y variable as the exponent used in the pressure formula. x1, x2, and x3 are equal to the rest of the equation.
	//Most of the equation is found by taking the x variables to the power of y.
	
	x1 = (1-((temp_lapse_rate*alt_1)/temp_init));
	x2 = (1-((temp_lapse_rate*alt_2)/temp_init));
	x3 = (1-((temp_lapse_rate*alt_3)/temp_init));
	
	y = ((grav*mol_air)/(uni_gas_const*temp_lapse_rate));
	
	//Defines power variables and sets them equal to x()^y.
	
	power1 = (pow(x1,y));
	power2 = (pow(x2,y));
	power3 = (pow(x3,y));
	
	//Takes the power variables and multiples by the initial pressure constant to get final pressure.
	
	pressure_1 =  pressure_init*power1;
	pressure_2 =  pressure_init*power2;
	pressure_3 =  pressure_init*power3;

	//Prints the table of values.
	
	printf("%17s%17s%17s%17s", "Altitude (m)", "Pressure (Pa)", "Pressure (mbar)", "Pressure (atm)");
	printf("\n%17.2lf%17Lf%17.2Lf%17.2Lf", alt_1, pressure_1, (pressure_1*0.01), (pressure_1/1.01325e5));
	printf("\n%17.2lf%17.2Lf%17.2Lf%17.2Lf", alt_2, pressure_2, (pressure_2*0.01), (pressure_2/1.01325e5));
	printf("\n%17.2lf%17.2Lf%17.2Lf%17.2Lf", alt_3, pressure_3, (pressure_3*0.01), (pressure_3/1.01325e5));
	return 0;
}


