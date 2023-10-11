#include <stdio.h>
/**
 * main - Entry point.
 * Description: Print the Fibonacci number upto 98
 * Return: 0
 */
#include <stdio.h>

int main(void)
{
	unsigned long num1 = 1, num2 = 2, next, count = 2;

	printf("%ld, %ld, ", num1, num2);

	while (count < 98)
	{
		next = num1 + num2;
		printf("%ld", next);

		count++;

		if (count < 98)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}

		num1 = num2;
		num2 = next;
	}

	return (0);
}
