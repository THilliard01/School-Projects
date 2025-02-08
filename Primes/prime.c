#include <stdio.h>

//Three main functions do the bulk of the program's work
void generate_set(unsigned int array[], unsigned int largest_num);
void find_primes(unsigned int parray[], unsigned int upper_bound);
void store_primes(unsigned int prime_array[], unsigned int array_size);

int main(void)
{
	//defines the variable used for most functions.
	
	unsigned int current_num;
	
	//Welcome statement
	
	printf("Welcome to the prime number generator! This program will generate and store prime numbers.\n");
	printf("Enter an integer and this program will generate all prime numbers up to that number.\n\n");
	
	//Code that gets the first user input. If the number is 1, the code will end.
	
	printf("Enter a positive integer greater than 1 and up to 500,000 or enter 1 to exit: ");
	scanf("%u", &current_num);
	
	//Done while the input isn't one and isn't negative. 
	
	while( (current_num != 1) && (current_num) > 1 )
	{
		//Defines an array with size n, where n is the number entered by the user.
		
		unsigned int num_set[current_num];
		
		//Transforms the array into a set of all integers between 1 and n.
		
		generate_set(num_set, current_num);
		
		//Finds all prime numbers in the set using the Sieve of Eratosthenes.
		
		find_primes(num_set, current_num);
		
		//Writes the current prime numbers into a file called primenumbers.txt.
		
		store_primes(num_set, current_num);
		
		//Success statement.
		
		printf("All done! Your prime numbers are stored in the file primenumbers.txt\n\n");
		
		//Reprompts user for input.
		
		printf("Enter a positive integer greater than 1 and up to 500000 or enter 1 to exit: ");
		scanf("%u", &current_num);	
	}
	printf("Exiting, have a good day!");
	
	return 0;
}

void generate_set(unsigned int array[], unsigned int largest_num)
{
	//For all elements in the entered set, this function will enter every positive integer greater than one up to the largest_num variable.
	
	for(int i=2; i<= largest_num; i++)
	{
		array[(i-2)] = i;
	}
}

void find_primes(unsigned int parray[], unsigned int upper_bound)
{
	//Defines an array with the four prime numbers in the Sieve.
	
	int div_nums[] = {2, 3, 5, 7};
	
	for(int i = 0; i<4; i++)//Outer loop changes the current prime number in the Sieve
	{
		for(int j = 0; j<=(upper_bound - 2); j++)
		/*Inner loop iterates through all elements of parray to determine if the number is prime. 
		  If not, the value is set to zero. Any zeros are ignored by the loop*/
		{
			if (parray[j] == 0)
				continue;
			else if (parray[j] != 0 && parray[j] % div_nums[i] == 0 && parray[j] != div_nums[i])
			{
				parray[j] = 0;
				continue;
			}	
		}
	
	}
}

void store_primes(unsigned int prime_array[], unsigned int array_size)
{
	//Defines file pointer for opening file.
	
	FILE *fp = NULL;
	
	//Opens primenumber.txt for appending. Also creates the file if it doesn't already exist.
	
	fp = fopen("primenumber.txt" , "a");
	fprintf(fp, "Prime numbers from 1 to %u:\n", array_size);
	
	//Loop prints all numbers in the array and ignores any zeros. All numbers printed are prime.
	
	for (int i = 0; i<= (array_size - 2); i++)
	{
		if(prime_array[i] != 0)
			fprintf(fp, "%u\n", prime_array[i]);
	}
	fclose (fp); 
}
