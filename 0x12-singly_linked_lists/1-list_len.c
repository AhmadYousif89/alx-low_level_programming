#include "lists.h"

/**
 * list_len - Print the number of elements in a list
 * @h: pointer to the list struct
 * Return: number of nodes in the list
 */
size_t list_len(const list_t *h)
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
