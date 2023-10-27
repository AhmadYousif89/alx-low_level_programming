#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the result of multiplying two numbers
 * @argc: count of args
 * @argv: array of char*
 * Return: (0) if two args provided, (1) otherwise
 */
int main(int argc, char *argv[])
{
	int i, arg, mul = 1;

	if (argc <= 2)
	{
		printf("Error\n");
		return (1);
	}

	for (i = 1; argc > 1; ++i)
	{
		arg = atoi(argv[i]);
		mul *= arg;
		argc--;
	}
	printf("%d\n", mul);

	return (0);
}
