#include "lists.h"

/**
 * print_list - Print the node values in a list and return its count
 * @h: pointer to the list struct
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	if (!h)
		return (i);

	while (h != NULL)
	{
		!h->str ? printf("[0] (nil)\n") : printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		i++;
	}

	return (i);
}
