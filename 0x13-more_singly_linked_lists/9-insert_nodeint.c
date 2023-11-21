#include "lists.h"

/**
 * insert_nodeint_at_index - Insert new node at a given position
 * @head: pointer to the pointer of listint
 * @idx: the index in listint to insert the new node
 * @n: number to fill the new node with
 * Return: pointer to the new node or NULL on failuer
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (!new || !head)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (current)
	{
		if (i == idx - 1)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
		i++;
	}

	/* Case of failuer */
	return (NULL);
}
