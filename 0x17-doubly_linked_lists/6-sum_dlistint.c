#include "lists.h"

/**
 * sum_dlistint - Sum of all n's in a doubly linked list.
 * @head: pointer to the head of dlistint
 * Return: the sum or 0
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *tmp = head;

	if (!head)
		return (sum);

	while (tmp)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}

	return (sum);
}
