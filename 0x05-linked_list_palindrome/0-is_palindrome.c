#include <stdlib.h>
#include "lists.h"

/**
 * _is_palindrome - check if a linked list is palindromic (helper)
 * @lhs: a pointer to the left-hand side of the list
 * @rhs_p: the address of a pointer to the right-hand side of the list
 *
 * Return: 1 if the list is a palindrome, otherwise 0
 */
static int _is_palindrome(listint_t *lhs, listint_t **rhs_p)
{
	listint_t *rhs = *rhs_p;

	if (!rhs)
	{
		*rhs_p = lhs;
		return (1);
	}
	rhs = rhs->next;
	if (!rhs)
	{
		*rhs_p = lhs->next;
		return (1);
	}
	rhs = rhs->next;
	if (_is_palindrome(lhs->next, &rhs) && lhs->n == rhs->n)
	{
		*rhs_p = rhs->next;
		return (1);
	}
	return (0);
}

/**
 * is_palindrome - check if a linked list is palindromic
 * @head: the address of a pointer to the head of a list
 *
 * Return: 1 if the list is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *rhs = NULL;

	if (head)
	{
		rhs = *head;
		return (_is_palindrome(rhs, &rhs));
	}
	return (0);
}
