#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void _print(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers
 * @argc: arg count
 * @argv: args array
 * Return: (0)
 */
int main(int argc, char *argv[])
{
	unsigned long mul;
	int i, j;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				_print("Error");
				exit(98);
			}
		}
	}

	mul = atoi(argv[1]) * atoi(argv[2]);
	printf("%lu\n", mul);

	return (0);
}
