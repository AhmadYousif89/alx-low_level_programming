#include "lists.h"

/**
 * get_nodeint_at_index - Get node by its index in the listint
 * @head: pointer to the listint
 * @index: the index of the node
 * Return: pointer to the node in listint
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *node = head;

	if (!node)
		return (NULL);

	while (node && i < index)
	{
		node = node->next;
		i++;
	}

	if (i != index)
		return (NULL);

	return (node);
}
