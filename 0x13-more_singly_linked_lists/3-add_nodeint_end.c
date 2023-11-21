#include "lists.h"

/**
 * create_node - Create a new node using the listint_t struct
 * @n: number to fill
 * Return: pointer to the list
 */
listint_t *create_node(const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_nodeint_end - Add new node at the end of listint_t
 * @head: pointer to a pointer to the list listint_t
 * @n: number to fill
 * Return: pointer to the list
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node = create_node(n);
	listint_t *current = *head;

	if (!node || !head)
		return (NULL);

	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = node;
	}
	else
		*head = node;

	return (node);
}
