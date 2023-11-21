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
	listint_t *current = *head; /* To keep the reference of the original head */
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!head || !*head || !new_node)
		return (NULL);

	new_node->n = n ? n : 0;

	/* Case idx is (0) i.e. inserting at the beggining */
	if (idx == 0)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}

	while (current)
	{
		if (i == idx - 1)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}

		current = current->next;
		i++;
	}

	return (new_node);
}
