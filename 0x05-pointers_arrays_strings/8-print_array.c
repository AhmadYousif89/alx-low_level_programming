#include <stdio.h>
#include "main.h"

/**
 * print_array - Print array elements
 * @a: data of type int *
 * @n: data of type int
 * Return: void
 */

void print_array(int *a, int n)
{
	int i = 0;

	for (i = 1; i <= n; i++)
	{
		if (i == n)
			printf("%d", a[i - 1]);
		else
			printf("%d, ", a[i - 1]);
	}
	printf("\n");
}
