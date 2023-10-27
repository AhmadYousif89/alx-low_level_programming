#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the result of adding two numbers
 * @argc: count of args
 * @argv: array of char*
 * Return: (0) if two args provided, (1) otherwise
 */
int main(int argc, char *argv[])
{
	int i, arg, add = 0;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < argc; i++)
	{
		arg = atoi(argv[i]);
		if (arg == '0')
		{
			printf("Error\n");
			return (1);
		}
		add += arg;
	}
	printf("%d\n", add);

	return (0);
}
