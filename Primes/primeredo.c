/**
 *  Tool for generating prime numbers and saving them
 * 
 *  Command-line tool for generating a list of prime numbers
 *  using the Sieve of Atkin. Prime numbers are stored in a
 *  file format (specified as .txt or .csv). 
 * 
 *  @author Toby Hilliard <tchilliard0@gmail.com>
 *  @version 1.0.0 
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>

 _Bool* sieve_of_atkin(int limit);
 int save_primes(_Bool* primes, int size);

 int main(void) {
    char* welcomemsg =  "Welcome to the prime number generator! "
                        "This program will generate and store prime numbers.";
    char* inputmsg = "Enter a positive integer greater than 1 and up to 500000"
                     " or enter 1 to exit: ";

    char buffer[8];
    int input = 0;
    puts(welcomemsg);
    while(!input || input != 1) {

        fputs(inputmsg, stdout);
        if (fgets(buffer, 8, stdin) == NULL || sscanf(buffer, "%d", &input) == 0
            || input < 0 || input > 500000) {
            puts("Error, invalid input.");
            exit(1);
        }

        if (input == 1)
            continue;

        _Bool* primes = sieve_of_atkin(input);

        if (save_primes(primes, input)) {
            printf("Error, failed to save primes.");
            free(primes);
            exit(3);
        }

        printf("Created a list of primes up to %d in primes.csv\n", input);
    }
    return 0;
 }

 /**
  *     Performs the Sieve of Atkin to find primes up to a number
  * 
  *     Takes a limit up to 500,000 and a pointer to a bool and returns
  *     an array of bools representing primes up to limit
  * 
  *     @param int limit
  *     @return _Bool* head
  *     @see https://www.geeksforgeeks.org/sieve-of-atkin/
  */
 _Bool* sieve_of_atkin(int limit) {
    //  We allocate with calloc to set the entire array to false easily
    _Bool* sieve = ((_Bool*)calloc(limit+1, sizeof(_Bool)));

    if (limit > 2)
        sieve[2] = 1;
    if (limit > 3)
        sieve[3] = 1;
    
    for (int x = 1; x * x <= limit; x++) {
        int powx = x*x;
        for (int y = 1; y * y <= limit; y++) {
            int powy = y*y;

            /*  We use bitwise XOR to track the number of solutions. n must have
                an odd number of solutions*/  
            int n = (4 * powx) + powy;
            if (n <= limit 
                && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= 1;
            
            n = (3 * powx) + powy;
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= 1;

            n = (3 * powx) - powy;
            if (x > y && n <= limit
                && n % 12 == 11)
                sieve[n] ^= 1;
            
        }
    }

    // Mark all multiples of square as nonprime
    for (int r = 5; r*r <= limit; r++) {
        if (sieve[r]) {
            for (int i = r*r; i <= limit; i += r*r) {
                sieve[i] = 0;
            }
        }
    }

    return sieve;
 }

 /**
  *     Store prime numbers in a .csv file
  *     
  *     Takes a boolean array and the array size and stores index values of "true"
  *     as prime numbers within a .csv file
  * 
  *     @param _Bool* primes
  *     @param int size
  *     @return sig
  */
 int save_primes(_Bool* primes, int size) {
    int sig = 0;

    FILE* fp = NULL;
    fp = fopen("primes.csv", "w");
    if (fp == NULL) {
        printf("Error, failed to open primes.csv\n");
        free(primes);
        exit(2);
    }
    
    for (int i = 2; i <= size; i++) {
        if (primes[i])
            fprintf(fp, "%d,", i);
    }
    fseek(fp, -1, SEEK_CUR);
    fprintf(fp, "\n");
    fclose(fp);

    return sig;
 }
