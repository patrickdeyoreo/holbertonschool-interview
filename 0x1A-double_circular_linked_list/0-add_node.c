#include <stdlib.h>
#include <string.h>

#include "list.h"

/**
 * add_node_end - add a node at the end of a circular doubly-linked list
 *
 * @list: list to modify
 * @str: string to add to the list
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
List *add_node_end(List **list, char *str)
{
	List *new = malloc(sizeof(*new));
	char *dup = strdup(str);

	if (!new || !dup)
	{
		free(new);
		free(dup);
		return (NULL);
	}
	new->str = dup;
	if (*list)
	{
		new->prev = (*list)->prev;
		new->prev->next = new;
		new->next = (*list);
		new->next->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		(*list) = new;
	}
	return (new);
}

/**
 * add_node_begin - add a node at the start of a circular doubly-linked list
 *
 * @list: list to modify
 * @str: string to add to the list
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
List *add_node_begin(List **list, char *str)
{
	List *new = malloc(sizeof(*new));
	char *dup = strdup(str);

	if (!new || !dup)
	{
		free(new);
		free(dup);
		return (NULL);
	}
	new->str = dup;
	if (*list)
	{
		new->prev = (*list)->prev;
		new->prev->next = new;
		new->next = (*list);
		new->next->prev = new;
		(*list) = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		(*list) = new;
	}
	return (new);
}
