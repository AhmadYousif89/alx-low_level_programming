#include "lists.h"

/**
 * list_len - Get the length of a list
 * @h: pointer to the list struct
 * Return: length of the list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	if (!h)
		return (i);

	while (h)
	{
		h = h->next;
		i++;
	}

	return (i);
}
