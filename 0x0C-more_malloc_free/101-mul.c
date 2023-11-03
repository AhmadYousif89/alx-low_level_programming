#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void _print(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}

int isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int convertToInt(char *s)
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

void multiplyNumbers(unsigned long int num)
{
	unsigned long int divisor = 1, digit, remainder;

	while (num * divisor > 9)
		divisor *= 10;

	/* Extract and print digits one by one */
	while (divisor >= 1)
	{
		digit = num / divisor;
		_putchar('0' + digit);
		remainder = num % divisor;
		num = remainder; /* Update number for the next iteration */
		divisor /= 10;	 /* Move to the next divisor */
	}
	_putchar('\n');
}

/**
 * main - Multiply two numbers
 * @argc: arg count
 * @argv: arg array
 * Return: (0)
 */
int main(int argc, char *argv[])
{
	unsigned long int arg1, arg2;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	arg1 = convertToInt(argv[1]);
	arg2 = convertToInt(argv[2]);
	multiplyNumbers(arg1 * arg2);

	return (0);
}
