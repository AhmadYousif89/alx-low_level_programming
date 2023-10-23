#include <stdio.h>

/**
 * print_diagsums - Print the chessboard
 * @a: pointer type int
 * @size: array size
 * Return: void
 */
void print_diagsums(int *a[], int size)
{
	int i, j, sum;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}
