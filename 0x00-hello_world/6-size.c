#include <stdio.h>

/**
 * main - Entry point
 * Print the size of diffrent data types using printf()
 * Return: 0 (Success)
 */

int main(void)
{
	char c;
	float f;
	int d;
	long int l;
	long long int x;

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(d));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(l));
	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(x));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));
	return (0);
}
