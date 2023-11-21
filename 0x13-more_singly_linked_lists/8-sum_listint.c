#include "lists.h"

/**
 * sum_listint - Calc the sum of nodes data (n)
 * @head: pointer to the listint
 * Return: the sum of data (n)
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *node = head;

	while (node)
	{
		sum += node->n;
		node = node->next;
	}

	return (sum);
}
