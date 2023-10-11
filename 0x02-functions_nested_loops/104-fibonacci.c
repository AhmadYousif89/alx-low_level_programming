#include <stdio.h>

/**
 * main - Entry point.
 * Description: Print the first 98 Fibonacci numbers, starting with 1 and 2
 * Return: 0
 */

int main(void)
{
	unsigned long i, previous, current;
	unsigned long previousP1, previousP2, currentP1, currentP2;
	unsigned long largeP1, largeP2;
	unsigned long target = 1000000000;

	previous = 1;
	current = 2;
	/* Print the first Fibonacci number */
	printf("%lu", previous);

	/* Generate and print Fibonacci sequence from 2nd to 90th term */
	for (i = 1; i < 91; i++)
	{
		printf(", %lu", current);
		/* Update previous and current values for the next iteration */
		current = current + previous;
		previous = current - previous;
	}
	/* Split large Fibonacci numbers into smaller parts ==> numbers over 1Bl */
	previousP1 = previous / target;
	previousP2 = previous % target;
	currentP1 = current / target;
	currentP2 = current % target;

	/* Generate and print Fibonacci sequence from 92nd to 98th term */
	for (i = 92; i <= 98; ++i)
	{
		largeP1 = currentP1 + (currentP2 / target);
		largeP2 = currentP2 % target;
		/* Print the next Fibonacci number */
		printf(", %lu%09lu", largeP1, largeP2);
		/* Update parts for the next iteration */
		currentP1 = currentP1 + previousP1;
		previousP1 = currentP1 - previousP1;
		currentP2 = currentP2 + previousP2;
		previousP2 = currentP2 - previousP2;
	}
	printf("\n");

	return (0);
}
