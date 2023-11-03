#include "main.h"
#include <stdlib.h>

void _print(char *s);
int _isDigit(char c);
unsigned long int convertToInt(char *s);
void multiplyNumbers(unsigned long int num);

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

/**
 * _print - Check if character is digit
 * @s: pointer type char
 * Return: void
 */
void _print(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}

/**
 * _isDigit - Check if character is digit
 * @c: arg of type int
 * Return: 1 or 0
 */
int _isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * convertToInt - Convert char to digit
 * @s: pointer type char
 * Return: number
 */
unsigned long int convertToInt(char *s)
{
	int sign = 1;
	unsigned long int i, j, res = 0;

	for (i = 0; !(_isDigit(s[i])); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	for (j = i; _isDigit(s[j]); j++)
	{
		res *= 10;
		res += s[i] - '0';
	}

	return (res * sign);
}

/**
 * multiplyNumbers - Print the result of multiplication of two numbers
 * @num: number type long
 * Return: void
 */
void multiplyNumbers(unsigned long int num)
{
	unsigned long int divisor = 1, digit;

	while (num / divisor > 9)
		divisor *= 10;

	/* Extract and print digits one by one */
	while (divisor >= 1)
	{
		digit = num / divisor;
		_putchar('0' + digit);
		num %= divisor;
		divisor /= 10;
	}
	_putchar('\n');
}
