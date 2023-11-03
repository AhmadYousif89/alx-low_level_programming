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
		res = res * 10 + (s[j] - '0');

	return (res * sign);
}

void multiplyNumbers(unsigned long int num)
{
	unsigned long int div = 1, i, res;

	for (i = 0; num / div > 9; i++, div *= 10)
		;

	for (; div >= 1; div /= 10)
	{
		res = num / div;
		_putchar('0' + res);
		num %= div;
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
	unsigned long int res;

	if (argc != 3)
	{
		_print("Error ");
		exit(98);
	}

	res = convertToLn(argv[1]) * convertToLn(argv[2]);
	multiplyNumbers(res);
	_putchar('\n');

	return (0);
}
