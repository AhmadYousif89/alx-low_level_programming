#include "main.h"
#include <stdio.h>
/**
 * times_table - Print a grid of 9 by 9.
 * Description: Print out a grid 9 * 9 representing the times table of number 9
 * Return: Void
 */

void times_table(void)
{
	int x, y;

	for (x = 0; x <= 9; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			if (y == 0)
				printf("%d", x * y);
			else
				printf("%2d", x * y);
			if (y < 9)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
}
