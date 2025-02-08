# PRIMES
*Generate prime numbers and stores them in a seperate file*

This program is the third program I completed for CSE1001 way back during my freshman year of college. This program seems pretty simple at first, but it's interesting to break into the "why" of the program

## Why Generate Prime Numbers?

Prime numbers have a lot of unique mathematical properties that make them useful for computing purposes. The purposes *I* most know them for is as the basis for public key cryptography. Popular PKE algorithms like RSA use prime number factorization as the basis for their security. In order to use prime numbers, you have to generate them. 

## Generating the Primes

Digging into the history of generating prime numbers, **Prime Sieves** are the most common way to generate primes. The Sieve of Erastothenes was the sieve I used in the original program. It is also, coiencidentaly, the easiest sieve to implement. However, the Sieve of Erastothenes has a complexity of $O(n \text{ log log } n)$. While this complexity isn't terrible, there are other sieves that can be run at $O(n)$ complexity. 

It should be noted that when generating prime numbers for uses in PKE, it's typically better to generate a large number and prove it is prime. However, for the sake of simplicity (and since I'd rather do that as an exercise in implementing RSA or something like it in the future), I'll keep the scope of this project to just this. 

## A New Sieve: The Sieve of Atkin
Our chosen Sieve for this event is going to be the Sieve of Atkin, developed in 2003 as an improved way to quickly generate primes. You can find an explanation from this [Wikipedia article](https://en.wikipedia.org/wiki/Sieve_of_Atkin). 
I'll be following along with a [guide from GeeksForGeeks](https://www.geeksforgeeks.org/sieve-of-atkin/) to get a better idea of how the algorithm works

## Implementation
In my first attempt of implementing a Sieve, I generated primes solely as a set of integers that were manually tesetd for values. This takes up more memory than is necessary, since the values stored in the array and the array index are identical. In this new implementation, we can simply create an array of boolean values. 

## A Quick Tangent on Booleans
While C and other languages have some implementations of boolean values, my mind wandered onto the topic of *how* these boolean values are implemented. In my experience, boolean values like TRUE and FALSE are typically some type of subclass or enum of ints, where 0 is false and 1 or any other number is true. However, I always thought it would be more space concious to implement them as some form of bit/byte unit. It turns out, the C99 macro _Bool does just this, using the CHAR_BIT identifier to create a boolean object. So, with that in mind, we can create a bool array using this new _Bool macro and save some serious space. 
