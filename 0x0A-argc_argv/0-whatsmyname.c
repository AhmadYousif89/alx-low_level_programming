#include <stdio.h>

/**
 * main - Print the program name
 * @argc: count of args
 * @argv: array of char*
 * Return: (0)
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[argc - 1]);
	return (0);
}
