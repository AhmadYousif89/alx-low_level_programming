#include <stdio.h>
#define fname __FILE__

/**
 * main - Print the name of the file using Macro (__FILE__)
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("%s\n", fname);
	return (0);
}
