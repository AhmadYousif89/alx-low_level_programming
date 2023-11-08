#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - Add two numbers
 * @a: number
 * @b: number
 * Return: number
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtract two numbers
 * @a: number
 * @b: number
 * Return: number
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiply two numbers
 * @a: number
 * @b: number
 * Return: number
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divid two numbers
 * @a: number
 * @b: number
 * Return: number
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - Modulo of two numbers
 * @a: number
 * @b: number
 * Return: number
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
