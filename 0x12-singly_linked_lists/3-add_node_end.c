#include "lists.h"

/**
 * create_node - Create a new node using the list struct
 * @str: pointer to the string field in list
 * Return: pointer to the list
 */
list_t *create_node(const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = new_node->str ? strlen(str) : 0;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node_end - Add new node at the end of a list
 * @head: pointer to a pointer to the list
 * @str: pointer to the string field in the node
 * Return: pointer to the list
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node = create_node(str);
	list_t *current = NULL;

	if (node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = node;
		return (NULL);
	}

	current = *head;
	while (current && current->next)
		current = current->next;

	current->next = node;

	return (node);
}
