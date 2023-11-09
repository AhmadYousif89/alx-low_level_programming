#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Print numbers with comma separator
 * @separator: pointer to string
 * @n: count of args
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list li;
	unsigned int i;

	va_start(li, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(li, int));
		if (separator && i < n - 1)
			printf("%s", separator);
	}

	va_end(li);
	printf("\n");
}
