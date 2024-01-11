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
	dlistint_t *current, *next_node, *new = malloc(sizeof(dlistint_t));
	/* Avoid derefrencing NULL pointers */
	if (!h || !new)
		return (NULL);
	/* Create new node */
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	/* Insert at the beginning of the list if idx = 0 */
	if (idx == 0 || !*h)
	{
		new->next = *h;
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
		if (!current) /* If last node is NULL */
		{
			free(new);
			return (NULL);
		}
	}
	/* Insert the new node */
	next_node = current->next; /* Save the current node as the next node */
	if (next_node)			   /* Case it was the last node */
		next_node->prev = new;
	current->next = new; /* update current node to have the new node */
	/* Update next and prev pointers of the new node */
	new->prev = current;
	new->next = next_node;

	return (new);
}
