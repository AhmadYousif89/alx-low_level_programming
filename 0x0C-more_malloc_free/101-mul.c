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
			if (!(isdigit(argv[i][j])))
			{
				_print("Error");
				exit(98);
			}
		}
	}

	multiplyNumbers(atol(argv[1]) * atol(argv[2]));

	return (0);
}
