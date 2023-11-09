#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Print numbers with comma separator
 * @separator: pointer to string
 * @n: const positive number
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;

	va_list(li);
	va_start(li, n);

	for (i = 0; i < n; i++)
	{
		int num = va_arg(li, int);

		if (i == n - 1)
			printf("%i\n", num);
		else
			printf("%i%s", num, separator);
	}
}
