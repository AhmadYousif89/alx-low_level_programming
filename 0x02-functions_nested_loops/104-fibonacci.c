#include <stdio.h>
/**
 * main - Entry point.
 * Description: Print the first 98 Fibonacci numbers, starting with 1 and 2
 * Return: 0
 */

int main(void)
{
	int i;
	unsigned long t1 = 0, t2 = 1;
	unsigned long nextTerm = t1 + t2;

	for (i = 3; i <= 98; ++i)
	{
		printf("%lu", nextTerm);
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;
		if (i < 98)
			printf(", ");
	}
	printf("\n");

	return (0);
}
