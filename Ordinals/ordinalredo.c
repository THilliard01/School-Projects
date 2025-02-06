/**
 *  Print the ordinal numbers in a sequence
 * 
 *  Get an integer from the user between 0 and 65535. 
 *  Print the ordinal numbers up to that number.
 *  Print the sum of those numbers.
 * 
 *  @author Toby Hilliard <tchilliard0@gmail.com>
 *  @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

void getUserInput(int *input, char *buffer);
void getOrd(int a);

int main(void) {
    int input = 0, sumtotal = 0;
    char buffer[7];

    printf("Welcome to the ordinal numbers simulator!\n");
    printf("Enter any positive integer between 0 and 65535 to begin.\n");
    printf("Enter a negative number to exit\n\n");

    getUserInput(&input, buffer);
    while(input > -1) {
        if (input > 65535) {
            printf("Error, input is out of range. Please try again.\n");
        }
        else {
            getOrd(input);
            sumtotal += input;
        }
        getUserInput(&input, buffer);
    }

    printf("The total of all the numbers you entered was %d.\n", sumtotal);
    return 0;
}

/**
 *  Function that gets an int from stdin
 * 
 *  Get a line from stdin and transform into int
 *  Exits program if detected input is invalid.
 * 
 *  @param int* input
 *  @param char* buffer
 *  @return int, initialized in input
 */
void getUserInput(int *input, char *buffer) {
    printf("Enter an integer: ");
    if(fgets(buffer, 7, stdin) == NULL || sscanf(buffer, "%d", input) == 0) {
        printf("Error, invalid input\n");
        exit(1);
    }
}

/**
 *  Function that prints the ordinal numbers up a limit
 * 
 *  Takes in an integer and prints the ordinal sequence up
 *  to the given integer
 * 
 *  @param int a
 */
void getOrd(int a) {
    int ordinal = 0;
    for (int i = 0; i <= a; i++) {
        ordinal = a - (a - i);

        if (((ordinal % 100 ) / 10) == 1)
        {
            printf("%dth Value\n", ordinal);
        }
        else switch(ordinal % 10) {
            case 1:
                printf("%dst Value\n", ordinal);
                break;
            case 2:
                printf("%dnd Value\n", ordinal);
                break;
            case 3:
                printf("%drd Value\n", ordinal);
                break;
            default:
                printf("%dth Value\n", ordinal);
                break;
        }
    }
}