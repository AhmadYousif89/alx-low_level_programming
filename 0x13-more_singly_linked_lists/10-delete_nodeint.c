#include "lists.h"

/**
 * delete_nodeint_at_index - Delete a node by a given index
 * @head: pointer to the pointer of listint
 * @index: the index in listint to insert the new node
 * Return: 1 on success, -1 on failuer
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *cur_node, *temp;

	if (!head || !*head)
		return (-1);

	cur_node = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(*head);
		return (1);
	}

	while (cur_node->next)
	{
		if (i == index - 1)
		{
			temp = cur_node->next;
			cur_node->next = temp->next;
			free(cur_node);
			return (i);
		}
		cur_node = cur_node->next;
		i++;
	}

	return (-1);
}
