#include <stdio.h>
#include "main.h"

/**
 * reverse_array - Reverse elements of a given array
 * @a: pointer of type int *
 * @n: number of type int
 * Return: void.
 */

void reverse_array(int *a, int n)
{
	int i, temp = 0;

	for (i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = temp;
		n--;
	}
}
