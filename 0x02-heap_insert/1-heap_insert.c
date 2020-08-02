#include "binary_trees.h"
#include <stdio.h>

/**
 * enqueue - enqueue a binary tree node
 * @rear: address of a pointer to the rear of a queue
 * @value: address of the binary tree node to enqueue
 * Return: On failure return NULL. Otherwise return a pointer to the new rear.
 */
static queue_t *enqueue(queue_t **rear, binary_tree_t *value)
{
	queue_t *new = NULL;

	if (rear)
	{
		new = malloc(sizeof(*new));
		if (new)
		{
			new->root = value;
			if (*rear)
			{
				new->next = (*rear)->next;
				(*rear)->next = new;
			}
			else
			{
				new->next = new;
			}
			*rear = new;
		}
	}
	return (new);
}

/**
 * dequeue - dequeue a binary tree node
 * @rear: address of a pointer to the rear of a queue
 * Return: If empty return NULL. Otherwise return a pointer to the queued item.
 */
static binary_tree_t *dequeue(queue_t **rear)
{
	queue_t *front = NULL;
	binary_tree_t *root = NULL;

	if (rear && *rear)
	{
		front = (*rear)->next;
		if (front == *rear)
			*rear = NULL;
		else
			(*rear)->next = front->next;
		root = front->root;
		free(front);
	}
	return (root);
}

/**
 * find_next_insertion - find the next insertion location in a complete tree
 * @root: address of a pointer to the root of a heap
 * @parent: address of a pointer in which to store the parent node (if any)
 * Return: address of the parent's pointer to the next insertion location
 */
static binary_tree_t **find_next_insertion(heap_t **root, heap_t **parent)
{
	queue_t *rear = NULL;

	if (root && parent && enqueue(&rear, *root))
	{
		while ((*parent = dequeue(&rear)))
		{
			root = &(*parent)->left;
			if (!*root)
				break;
			root = &(*parent)->right;
			if (!*root)
				break;
			root = NULL;
			if (!enqueue(&rear, (*parent)->left))
				break;
			if (!enqueue(&rear, (*parent)->right))
				break;
		}
		while (dequeue(&rear))
			;
	}
	return (root);
}

/**
 * heap_insert - insert a value into a max binary heap
 * @root: address of a pointer to the root node
 * @value: integer to be inserted
 * Return: On failure return NULL. Otherwise return a pointer to the new node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *temp = NULL;

	root = find_next_insertion(root, &temp);
	if (root)
	{
		temp = *root = binary_tree_node(temp, value);
		if (temp)
		{
			while (temp->parent && temp->n > temp->parent->n)
			{
				SWAP(temp->n, temp->parent->n);
				temp = temp->parent;
			}
		}
	}
	return (temp);
}
