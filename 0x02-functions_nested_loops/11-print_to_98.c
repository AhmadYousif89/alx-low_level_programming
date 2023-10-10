#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Print some numbers.
 * Description: Print the given number up to number 98.
 * @num: data of type integer
 * Return: Void
 */
void print_to_98(int num)
{
	int i;
	int target = 98;

	for (i = num; i <= target; i++)
	{
		printf("%d", i);
		if (i < 98)
		{
			printf(" ,");
		}
	}
	_putchar('\n');
}
