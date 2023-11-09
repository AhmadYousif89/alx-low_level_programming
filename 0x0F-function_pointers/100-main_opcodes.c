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

	unsigned char *mainAddress = (unsigned char *)main;

	for (i = 0; i < nb; i++)
	{
		if (i == nb - 1)
			printf("%02x\n", mainAddress[i]);
		else
			printf("%02x ", mainAddress[i]);
	}

	return (0);
}
