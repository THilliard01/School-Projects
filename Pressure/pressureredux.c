/**
 *  Calculate barometric pressure with respect to Earth's surface
 * 
 *  Program that calculates barometric pressure with reference
 *  to the Earth's surface. This program provides a command-line
 *  module to enter a given altitude and print this data to the
 *  screen, as well as perform bulk calculations and export the
 *  results to a file. 
 * 
 *  Calculations performed with this program attempt to provide
 *  and answer that avoids loss of significance. 
 * 
 *  @author Toby Hilliard <thilliard0@gmail.com>
 *  @version 1.0.0
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Define global variables for data persistence */
const double pressure_init = 101325 /*Pa*/;
const double baro_power = (9.80665 * 0.02896968) * (1 / (8.314462618 * 0.00976));
const double baro_ratio = 0.00976 / 288.16;

double calculate_pressure(double height);
void user_calculation();

int main(int argc, char *argv[]) {
    if (argc == 1) {
        user_calculation();
    }

    else {
        char arg[2];
        if (strlen(argv[1]) != 2) {
            printf("ERROR: Invalid flag/no flag given.\n");
            exit(-1);
        }

        else {
            strncpy(arg, argv[1], 2);
            switch(arg[1]) {
                case 'h':
                    printf("PRESSURE REDUX: A CLI for calculating Barometric PRESSURE\n");
                    printf("USAGE: \n");
                    printf("    ./pressureredux [options]\n");
                    printf("OPTIONS:\n");
                    printf("    -h                  Displays usage information\n");
                    printf("    -i                  Calculate altitude from stdin. Default behavior.\n");
                    printf("    -l [LIST]           Calculate altitude from provided list\n");
                    printf("    -b [FILENAME]       Calculate altitude from provided CSV file\n");
                    break;
                case 'i':
                    user_calculation();
                    break;
                case 'b':
                    char filename[50];
                    strncpy(filename, argv[2], 50);

                    //  Validate given file is a CSV
                    char filetype[5];
                    strncpy(filetype, filename + (strlen(filename) - 4), 5);
                    if (strcmp(".csv", filetype) != 0) {
                        printf("Error, file not csv.\n");
                        exit(1);
                    }

                    //  Open and read
                    FILE *inputfile = fopen(filename, "r");
                    if (inputfile == NULL) {
                        printf("Error, file name is incorrect/doesn't exist.\n");
                        exit(1);
                    }

                    char buffer[1024];
                    while (fgets(buffer, 1024, inputfile)) {
                        char *token = strtok(buffer, ",");

                        while (token != NULL) {
                            double alt = atof(token);
                            printf("Pressure for altitude %.2lf is %lf Pa\n", alt, calculate_pressure(alt));
                            token = strtok(NULL, ",");
                        }
                    }
                    break;
                case 'l':
                    int inputs = argc - 2;
                    if (inputs) {
                        for (int i = 1; i <= inputs; i++) {
                            double alt = atof(argv[i+1]);
                            printf("Pressure for altitude %.2lf is %lf Pa\n", alt, calculate_pressure(alt));
                        }
                    }
                    else {
                        printf("ERROR: No list provided.\n");
                        exit(-1);
                    }
                    break;
                default:
                    printf("ERROR: Invalid flag.\n");
                    exit(-1);
            }
        }
    }
    return 0;
}

/**
 *  Calculate pressure from stdin
 * 
 *  Function to handle an invoke from CL with no params or
 *  the -i flag. Prompts user for height and prints the
 *  pressure in Pascals. 
 */
void user_calculation() {
    double height = 0;
    printf("Enter an altitude (in meters): ");
    scanf("%lf", &height);
    printf("Pressure for altitude %.2lf is %lf Pa\n", height, calculate_pressure(height));
}

/**
 *  Calculate pressure
 * 
 *  Calculates the barometric pressure for a given height with
 *  respect to the surface of the Earth.
 */
double calculate_pressure(double height) {
    double pressure = pressure_init * pow((1- (height*baro_ratio)), baro_power); 
    return pressure;
}