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
	listint_t *cur_node = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node || !cur_node)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = cur_node;
		*head = new_node;
		return (new_node);
	}

	while (cur_node)
	{
		if (i == idx - 1)
		{
			new_node->next = cur_node->next;
			cur_node->next = new_node;
			return (new_node);
		}
		cur_node = cur_node->next;
		i++;
	}

	/* Case of failuer */
	return (NULL);
}
