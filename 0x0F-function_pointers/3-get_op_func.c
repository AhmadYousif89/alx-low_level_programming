#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * get_op_func - Return the corresponding calc operation function
 * @s: pointer to the op string
 * Return: pointer to the calc op function
 */
int (*get_op_func(char *s))(int, int)
{
	int i = 0;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}};

	while (ops[i].op != NULL)
	{ /* Compare the value of (s) against the operator */
		if (*ops[i].op == *s && *(s + 1) == '\0')
			return (ops[i].f);
		i++;
	}

	printf("Error\n");
	exit(99);
	return (NULL);
}
