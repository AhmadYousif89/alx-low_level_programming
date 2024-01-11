#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert new node at a given index of the dlistint.
 * @h: pointer to the head of dlistint
 * @idx: the position to insert the node
 * @n: the data as a number
 * Return: pointer to the new element or NULL on failuer
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new = malloc(sizeof(dlistint_t));
	/* Avoid derefrencing NULL pointers */
	if (!h || !new)
		return (NULL);
	/* Create new node */
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	/* Insert at the beginning of the list if idx = 0 or list is empty */
	if (idx == 0 || !*h)
	{
		new->next = *h;
		if (*h)
			(*h)->prev = new;
		*h = new;
		return (new);
	}
	/* Traverse the list to idx position */
	current = *h;
	while (idx - 1)
	{
		current = current->next;
		idx--;
		if (!current) /* last node is NULL or idx is out of range */
		{
			free(new);
			return (NULL);
		}
	}
	/* Insert the new node and prev pointers of the new node */
	new->prev = current;
	new->next = current->next;
	if (current->next) /* Case it was the last node */
		current->next->prev = new;
	current->next = new; /* update current node to have the new node */

	return (new);
}
