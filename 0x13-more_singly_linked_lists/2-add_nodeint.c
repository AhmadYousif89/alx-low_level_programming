#include "lists.h"

/**
 * create_node - Create a new node using the listint_t struct
 * @n: number to fill
 * Return: pointer to the list
 */
listint_t *create_node(const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_nodeint - Add new node at the start of a listint_t
 * @head: pointer to a pointer to the list
 * @n: number to fill
 * Return: pointer to the list
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node = create_node(n);

	if (!node)
		return (NULL);

	node->next = *head;
	*head = node;

	return (*head);
}
