#include <stdio.h>

/**
 * print_chessboard - Print the chessboard
 * @a: pointer type char
 * Return: Pointer to the beginning of the located substring, or NULL
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
