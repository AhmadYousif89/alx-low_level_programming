#include <stdio.h>

/**
 * main - Print the all args including the file name
 * @argc: count of args
 * @argv: array of char*
 * Return: (0)
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; argc > 0; ++i)
	{
		printf("%s\n", argv[i]);
		argc--;
	}

	return (0);
}
