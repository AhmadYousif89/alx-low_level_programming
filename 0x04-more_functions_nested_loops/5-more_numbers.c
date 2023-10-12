#include "main.h"

/**
 * more_numbers - 0 to 9
 * Description - Prints the numbers, from [0 .. 9] except [2 ,4]
 * Return: Void
 */

void more_numbers(void)
{
	int i;
	int j;

	for (i = 0; i <= 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j >= 10)
				_putchar(j / 10 + '0');
			_putchar(j % 10 + '0');
		}
		_putchar('\n');
	}
}
