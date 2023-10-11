#include <stdio.h>
/**
 * main - Entry point.
 * Description: Print the Fibonacci number upto 50
 * Return: 0
 */
#include <stdio.h>

int main(void)
{
	int i, next;
	int limit = 50;
	int first = 0;
	int second = 1;

	for (i = 0; i <= limit; ++i)
	{
		printf("%d", first);
		if (i < limit)
			printf(", \n");
		next = first + second;
		first = second;
		second = next;
	}

	return (0);
}
