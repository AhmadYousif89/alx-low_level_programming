#include <stdio.h>
#include <stdlib.h>

/**
 * struct dlistint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 *
 * Description: Doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t linked list.
 * @head: Pointer to the head of the doubly linked list.
 * @n: Integer value to be stored in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, int n)
{
	dlistint_t *new_node, *last_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
		new_node->prev = last_node;
	}

	return (new_node);
}

/**
 * print_dlistint - Prints all the elements of a dlistint_t linked list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return: Number of nodes in the doubly linked list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * free_dlistint - Frees a dlistint_t linked list.
 * @head: Pointer to the head of the doubly linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the doubly linked list.
 * @index: Index of the node to be retrieved (starting from 0).
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current = head;

	for (i = 0; current != NULL && i < index; i++)
	{
		current = current->next;
	}

	return current;
}

/* Your other functions (add_dnodeint_end, print_dlistint, free_dlistint) go here */

int main(void)
{
	dlistint_t *head;
	dlistint_t *node;

	int index = 5;

	head = NULL;
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 98);
	add_dnodeint_end(&head, 402);
	add_dnodeint_end(&head, 1024);
	print_dlistint(head);
	node = get_dnodeint_at_index(head, index);
	printf("The n value of node with index #%d is %d\n", index, node->n);
	free_dlistint(head);
	head = NULL;

	return (EXIT_SUCCESS);
}
