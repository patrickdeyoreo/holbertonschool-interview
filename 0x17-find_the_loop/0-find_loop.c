#include "lists.h"

/**
 * find_listint_loop - locate a loop in a singly linked list
 *
 * @head: pointer to the head of a list
 *
 * Return: If there is no loop, return NULL.
 * Otherwise, return a pointer to the first node in the loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head;
	listint_t *slow = head;

	while (fast)
	{
		fast = fast->next;
		if (!fast)
			break;
		fast = fast->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (fast)
	{
		while (head != slow)
		{
			head = head->next;
			slow = slow->next;
		}
		return (head);
	}
	return (NULL);
}
