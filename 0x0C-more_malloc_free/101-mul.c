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
}

/**
 * convertToLn - Convert string to number
 * @s:  pointer
 * Return: long number
 */
int convertToLn(char *s)
{
	int sign = 1;
	unsigned long int i, j, res = 0;

	for (i = 0; !((s[i] >= '0' && s[i] <= '9')); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	for (j = i; (s[i] >= '0' && s[i] <= '9'); j++)
	{
		res *= 10;
		res += (s[j] - '0');
	}

	return (res * sign);
}

/**
 * multiplyNumbers - .
 * @num: long number
 * Return: (0)
 */
void multiplyNumbers(unsigned long int num)
{
	unsigned long int div = 1, i, res;

	for (i = 0; num / div > 9; i++, div *= 10)
		;
	for (; div >= 1; num %= div, div /= 10)
	{
		res = num / div;
		_putchar('0' + res);
	}
}

/**
 * main - Multiplies two positive numbers
 * @argc: arg count
 * @argv: args array
 * Return: (0)
 */
int main(int argc, char *argv[])
{
	(void)argc;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	multiplyNumbers(convertToLn(argv[1]) * convertToLn(argv[2]));
	_putchar('\n');

	return (0);
}
