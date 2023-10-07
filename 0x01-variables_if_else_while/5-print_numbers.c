#include <stdlib.h>
#include <time.h>

/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */

/**
 * main - Entry point
 * Print 0..9 ;
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		printf("%d",i);
	return (0);
}
