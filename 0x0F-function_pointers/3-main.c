#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point to Calc
 * @argc: count of args
 * @argv: list of args
 * Return: (0).
 */
int main(int argc, char *argv[])
{
	char op;
	int result, arg2;
	int (*calc)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = *argv[2]; /* the operator */
	arg2 = atoi(argv[3]) == 0;
	if ((op == '/' || op == '%') && arg2)
	{
		printf("Error\n");
		exit(100);
	}

	calc = get_op_func(argv[2]);
	result = calc(atoi(argv[1]), atoi(argv[3]));
	printf("%i\n", result);

	return (0);
}
