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
	int res;
	int (*p)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	p = get_op_func(argv[2]);
	res = p(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", res);

	return (0);
}
