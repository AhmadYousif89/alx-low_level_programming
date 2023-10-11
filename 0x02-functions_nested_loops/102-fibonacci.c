#include <stdio.h>

/**
 * main - Entry point.
 * Description: Print the Fibonacci number upto 50
 * Return: 0
 */

int main(void)
{
	int i;
	int limit = 50;
	long next, first = 0, second = 1;

	for (i = 0; i < limit; i++)
	{
		next = first + second;
		printf("%ld", next);
		first = second;
		second = next;
		if (i < limit - 1)
			printf(", ");
	}
	printf("\n");

	return (0);
}
