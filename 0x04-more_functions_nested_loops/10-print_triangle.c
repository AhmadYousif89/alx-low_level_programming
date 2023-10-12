#include "main.h"

/**
 * print_triangle - Draw a triangle in the terminal
 * Description - Print a triangle shape with the character (#)
 * @size: number
 * Return: Void
 */

void print_triangle(int size)
{
	int y;
	int x;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	/* If size = 10 */
	/* 10 vertical lines */
	for (y = 0; y < size; y++)
	{
		/* First iteration y = 0 and x = 10 - 1 = 9 */
		/* By decrementing (x) we start drwaing from right to left */
		for (x = size - 1; x >= 0; x--)
		{
			/* First iteration prints (space) x9 times and (#) 1 time */
			if (x > y)
				_putchar(' ');
			else
				_putchar('#');
		}
		_putchar('\n');
	}
}
