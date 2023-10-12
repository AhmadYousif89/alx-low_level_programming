#include "main.h"

/**
 * print_square - Draw squar of (#)
 * Description - Print the squar shape of character (#)
 * @size: number
 * Return: Void
 */

void print_square(int size)
{
	int i;
	int j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
