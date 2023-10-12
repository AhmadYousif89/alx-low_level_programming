#include "main.h"

/**
 * print_line - Draw lines in the terminal
 * Description - Print straight lines in the terminal based on given number
 * @n: number of lines to be print
 * Return: Void
 */

void print_line(int n)
{
	int i;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}
