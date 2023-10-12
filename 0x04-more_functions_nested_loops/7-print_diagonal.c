#include "main.h"

/**
 * print_diagonal - Draw (\) in the terminal
 * Description - Print the character (\) in the terminal based on given number
 * @n: number
 * Return: Void
 */

void print_diagonal(int n)
{
	int i;
	int j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			/* Skip the first iteration of (i) and just print (\)*/
			if (j == i)
				_putchar('\\');
			/* Print (space) after the second iteration of (i)*/
			else
				_putchar(' ');
		}
		_putchar('\n');
	}
}
