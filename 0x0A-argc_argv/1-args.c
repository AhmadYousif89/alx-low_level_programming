#include <stdio.h>

/**
 * main - Print the count of args excluding the file name
 * @argc: count of args
 * @argv: array of char*
 * Return: (0)
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
