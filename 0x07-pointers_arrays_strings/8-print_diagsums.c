#include <stdio.h>

/**
 * print_diagsums - Print the sum of the two diagonals of a square matrix
 * @a: pointer type int
 * @size: array size
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int first_sum = 0;
	int second_sum = 0;

	for (int i = 0; i < size; i++)
	{
		first_sum += *(a + i * size + i);
		second_sum += *(a + i * size + (size - 1 - i));
	}

	printf("%d, %d\n", first_sum, second_sum);
}
