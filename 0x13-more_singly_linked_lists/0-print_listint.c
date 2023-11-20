#include "lists.h"

/**
 * print_list - Print the node values in a list and return its count
 * @h: pointer to the list struct
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	size_t n = 0;

	if (!h)
		return (n);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		n++;
	}

	return (n);
}
