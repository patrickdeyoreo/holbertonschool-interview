#include "binary_trees.h"

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
 * Return: address of the dequeued binary tree node
 */
static binary_tree_t *dequeue(queue_t **rear)
{
	queue_t *front = NULL;
	binary_tree_t *root = NULL;

	if (rear && *rear)
	{
		root = front->root;
		front = (*rear)->next;
		(*rear)->next = front->next;
		free(front);
		if (front == *rear)
			*rear = NULL;
	}
	return (root);
}

/**
 * heap_insert - insert a value into a max binary heap
 * @root: address of a pointer to the root node
 * @value: integer to be inserted
 */
heap_t *heap_insert(heap_t **root, int value)
{
}
