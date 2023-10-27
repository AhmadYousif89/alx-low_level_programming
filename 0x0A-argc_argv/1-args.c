#include <stdio.h>

/**
 * main - Print the count of args excluding the file name
 * @argc: count of args
 * @argv: array of char*
 * Return: (0)
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc <= 1)
		printf("%d\n", argc - 1);
	else
	{
		while (*argv)
		{
			i++;
			argv++;
		}
		printf("%d\n", i - 1);
	}

	return (0);
}
