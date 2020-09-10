#include "lists.h"

/**
 * check_cycle - determines if a linked list contains a loop
 * @list: a pointer to the start of a list
 * Return: 1 if the list contains a loop, otherwise 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	while (fast && (fast = fast->next))
	{
		slow = slow->next;
		fast = fast->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
