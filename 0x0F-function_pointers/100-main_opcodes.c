#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the opcodes
 * @argc: count of arguments
 * @argv: list of arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i, nb; /* nb => number of bytes */
	char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	nb = atoi(argv[1]);

	if (nb < 0)
	{
		printf("Error\n");
		exit(2);
	}

	ptr = (char *)main;

	for (int i = 0; i < nb; i++)
	{
		printf("%02x", ptr[i]);
	}

	printf("\n");
	return (0);
}
