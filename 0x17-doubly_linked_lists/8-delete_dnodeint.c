#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at a given index of the dlistint.
 * @head: pointer to the head of dlistint
 * @index: the position to insert the node
 * Return: 1 on success or 0 on failuer
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current;

	if (!head || !*head)
		return (-1);

	current = *head;
	if (index == 0)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current && i++ < index)
		current = current->next;

	if (!current) /* Index is out of range */
		return (-1);

	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	free(current);
	return (1);
}
