#include <stdio.h>

/**
 * main - Entry point
 * Description: Calculate the largest prime factor for a given number.
 * Return: (0)
 */

int main(void)
{
	long num = 11456233;
	long largest_prime_factor;
	long smallest_prime_factor = 2;

	/* Loop over (num) until it reach (1) */
	while (num > 1)
	{
		/* Increment the smallest possible prime factor */
		/* if this factor doesn't divide the given (num) evenly */
		while (num % smallest_prime_factor != 0)
		{
			smallest_prime_factor++;
		}
		/* Divide (num) on the new smallest prime factor */
		num /= smallest_prime_factor;
		/* The largest prime factor is the last possible */
		/* dividable number for (num) */
		largest_prime_factor = smallest_prime_factor;
	}
	printf("%ld\n", largest_prime_factor);

	return (0);
}
