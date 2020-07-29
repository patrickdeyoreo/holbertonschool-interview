#include "lists.h"

/**
 * insert_node - insert a node into a linked list sorted in ascending order
 * @head: the address of a pointer to the first item in the list
 * @number: the number to insert
 * Return: upon success, a pointer to the new node; upon failure, NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = head ? malloc(sizeof(*new)) : NULL;

	if (new)
	{
		new->n = number;
		while (*head && (*head)->n < new->n)
		{
			head = &(*head)->next;
		}
		new->next = *head;
		*head = new;
	}
	return (new);
}
