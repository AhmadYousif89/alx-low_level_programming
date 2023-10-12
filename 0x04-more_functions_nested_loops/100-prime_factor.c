#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 * Description: Calculate the largest prime factor for a given number.
 * Return: (0)
 */

int main(void)
{
	/*int i;*/
	long num = 612852475143;
	long largest_prime_factor = 2;
	/*int squar_num = sqrt(num);*/

	/* Loop over (num) until it reach (1) */
	while (num > 1)
	{
		if (num % largest_prime_factor == 0)
		{
			num /= largest_prime_factor;
		}
		else
			/* Increment the largest possible prime factor */
			largest_prime_factor++;
	}

	printf("%ld\n", largest_prime_factor);

	return (0);
}
