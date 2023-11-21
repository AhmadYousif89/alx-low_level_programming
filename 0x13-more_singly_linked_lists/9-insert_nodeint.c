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
	listint_t *new_node = create_node(n);
	listint_t *current = *head; /* To keep the reference of the original head */

	if (!current || !new_node)
		return (NULL);

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

	/* Case the insertion failed */
	free(new_node);
	return (new_node);
}
