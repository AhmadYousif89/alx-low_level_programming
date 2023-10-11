#include <stdio.h>
/**
 * main - Entry point.
 * Description: Print the Fibonacci number upto 98
 * Return: 0
 */
#include <stdio.h>

int main(void)
{
	unsigned long long num1 = 1, num2 = 2, next;
	int count = 2;

	printf("%llu, %llu, ", num1, num2);

	while (count < 98)
	{
		next = num1 + num2;
		printf("%llu", next);

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
