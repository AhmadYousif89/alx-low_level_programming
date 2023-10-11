#include <stdio.h>

/**
 * main - Entry point.
 * Description: Prints the sum of even-value Fibonacci number not exceeding 4m
 * Return: 0
 */

int main(void)
{
	unsigned long fib1 = 0, fib2 = 1, next;
	unsigned long max = 4000000;
	float sum;

	while (1)
	{
		next = fib1 + fib2;
		if (next > max)
			break;

		if (next % 2 == 0)
			sum = sum + next;

		fib1 = fib2;
		fib2 = next;
	}
	printf("%0.f\n", sum);

	return (0);
}
