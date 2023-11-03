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

/**
 * convertToLn - Convert string to number
 * @s:  pointer
 * Return: long number
 */
unsigned long int convertToLn(char *s)
{
	int sign = 1;
	unsigned long int i, j, res = 0;

	for (i = 0; !(isdigit(s[i])); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	for (j = i; isdigit(s[j]); j++)
		res = res * 10 + s[i] - '0';

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
	unsigned long int mul;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	mul = convertToLn(argv[1]) * convertToLn(argv[2]);
	printf("%lu\n", mul);

	return (0);
}
