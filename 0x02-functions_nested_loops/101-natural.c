#include <stdio.h>
/**
 * main - Entry point.
 * Description: Print the sum of all multiples of 3 and 5
 * Return: 0
 */
#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	for (i = 1; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	printf("%d\n", sum);

	return (0);
}
