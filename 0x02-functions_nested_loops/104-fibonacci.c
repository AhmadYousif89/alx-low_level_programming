#include <stdio.h>
/**
 * main - Entry point.
 * Description: Print the Fibonacci number upto 98
 * Return: 0
 */
#include <stdio.h>

int main(void)
{
	unsigned long fib1 = 1, fib2 = 2, next;
	int count = 2;

	printf("%lu, %lu, ", fib1, fib2);

	while (count < 98)
	{
		next = fib1 + fib2;
		printf("%lu", next);

		count++;

		if (count < 98)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}

		fib1 = fib2;
		fib2 = next;
	}

	return (0);
}
