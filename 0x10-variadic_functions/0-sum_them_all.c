#include <stdarg.h>

/**
 * sum_them_all - Return the sum of the var-args
 * @n: constant positive number
 * Return: the sum
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;

	va_list(li);
	va_start(li, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
		sum += va_arg(li, int);

	return (sum);
}
