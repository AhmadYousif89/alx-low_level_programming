#include "lists.h"

/**
 * get_dnodeint_at_index - Get node at index position in a doubly linked list.
 * @head: pointer to the head of dlistint
 * @index: the index of the targeted node
 * Return: pointer to the targeted node or NULL on failuer
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *temp = head;

	if (!head)
		return (NULL);

	/* Traverse the list to find matching index */
	while (temp)
	{
		if (i++ == index)
			return (temp);
		temp = temp->next;
	}

	return (NULL);
}
