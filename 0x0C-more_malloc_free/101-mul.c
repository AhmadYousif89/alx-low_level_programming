#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * _print - Print string using _putchar
 * @s:  pointer
 * Return: void
 */
void _print(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}

unsigned long int convertToInt(char *s)
{
	int sign = 1;
	unsigned long int i, j, res = 0;

	for (i = 0; !(isDigit(s[i])); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	for (j = i; isDigit(s[j]); j++)
	{
		res *= 10;
		res += s[i] - '0';
	}

	return (res * sign);
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
	char *arg1;
	char *arg2;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	arg1 = argv[1];
	arg2 = argv[2];

	for (i = 0; arg1[i] != '\0'; i++)
	{
		if (!isdigit(arg1[i]))
		{
			_print("Error");
			exit(98);
		}
	}

	for (i = 0; arg2[i] != '\0'; i++)
	{
		if (!isdigit(arg2[i]))
		{
			_print("Error");
			exit(98);
		}
	}

	mul = convertToInt(argv[1]) * convertToInt(argv[2]);
	printf("%lu\n", mul);

	return (0);
}
