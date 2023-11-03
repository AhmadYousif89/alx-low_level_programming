#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
	int i;
	unsigned long int mul;
	char *num1_str;
	char *num2_str;

	if (argc != 3)
	{
		printf("Error\n");
		return 98;
	}

	num1_str = argv[1];
	num2_str = argv[2];

	for (i = 0; num1_str[i] != '\0'; i++)
	{
		if (!isdigit(num1_str[i]))
		{
			printf("Error\n");
			return 98;
		}
	}

	for (i = 0; num2_str[i] != '\0'; i++)
	{
		if (!isdigit(num2_str[i]))
		{
			printf("Error\n");
			return 98;
		}
	}

	mul = atoi(argv[1]) * atoi(argv[2]);
	printf("%lu\n", mul);

	return 0;
}