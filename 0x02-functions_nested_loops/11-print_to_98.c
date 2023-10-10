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
	int target = 98;

	while (num <= target)
	{
		printf("%d", num);
		if (num < target)
			printf(", ");
		else
		{
			printf("\n");
			return;
		}
		num++;
	}

	while (num >= target)
	{
		printf("%d", num);
		if (num > target)
			printf(", ");
		else
		{
			printf("\n");
			return;
		}
		num--;
	}
}
