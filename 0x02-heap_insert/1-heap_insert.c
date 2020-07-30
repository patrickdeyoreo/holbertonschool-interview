#include "binary_trees.h"
#include <stdio.h>

#define SWAP(m, n) ((m) ^= (n), (n) ^= (m), (m) ^= (n))

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
 * Return: If empty return NULL. Otherwise return a pointer to the queued node.
 */
static binary_tree_t *dequeue(queue_t **rear)
{
	queue_t *temp = NULL;
	binary_tree_t *root = NULL;

	if (rear && *rear)
	{
		temp = (*rear)->next;
		if (temp == *rear)
			*rear = NULL;
		else
			(*rear)->next = temp->next;
		root = temp->root;
		free(temp);
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
	queue_t *rear = NULL;
	heap_t *temp = NULL;

	if (root)
	{
		if (*root)
		{
			if (enqueue(&rear, *root))
			{
				while ((temp = dequeue(&rear)))
				{
					root = &temp->left;
					if (!*root)
						break;
					root = &temp->right;
					if (!*root)
						break;
					root = NULL;
					if (!(enqueue(&rear, temp->left) && enqueue(&rear, temp->right)))
						break;
				}
				while (rear)
					dequeue(&rear);
			}
		}
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
	}
	return (temp);
}
