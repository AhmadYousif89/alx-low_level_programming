#include "main.h"
#include <stdio.h>
/**
 * print_times_table - Print a grid of (n) by (n).
 * Description: Print out a grid based on a given number
 * representing the times table of that number
 * @n: data of type int
 * Return: Void
 */

void print_times_table(int n)
{
	int x, y, multi;

	if (n > 90)
		return;

	for (x = 0; x <= n; x++)
	{
		for (y = 0; y <= n; y++)
		{
			multi = x * y;
			if (y == 0)
				printf("%d", multi);
			else
				printf("%3d", multi);
			if (y < n)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
}
