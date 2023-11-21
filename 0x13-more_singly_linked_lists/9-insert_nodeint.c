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
	unsigned int i;
	listint_t *new;
	listint_t *current = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; current && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		else
			current = current->next;
	}

	/* Case of failuer */
	return (NULL);
}
