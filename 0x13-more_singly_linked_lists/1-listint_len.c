#include "lists.h"

/**
 * listint_t - Get the length of the listint
 * @h: pointer to the list struct
 * Return: length of the list
 */
size_t listint_len(const listint_t *h)
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
