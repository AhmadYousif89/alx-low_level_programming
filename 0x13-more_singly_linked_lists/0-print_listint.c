#include "lists.h"

/**
 * print_listint - Print the listint values and return its element count
 * @h: pointer to the list struct
 * Return: number of nodes in the listint
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
