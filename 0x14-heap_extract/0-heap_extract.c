#include <stdlib.h>

#include "binary_trees.h"

/**
 * _queue_enqueue - enqueue an element
 *
 * @rear: address of a pointer to the rear of a queue
 * @data: pointer to data to enqueue
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new rear of the queue.
 */
static queue_t *_queue_enqueue(queue_t **rear, void *data)
{
	queue_t *node = NULL;

	if (!rear)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = *rear ? (*rear)->next : node;
	if (*rear)
		(*rear)->next = node;
	*rear = node;
	return (node);
}

/**
 * _queue_dequeue - dequeue an element
 *
 * @rear: address of a pointer to the rear of a queue
 *
 * Return: If the queue is empty, return NULL.
 * Otherwise, return a pointer to dequeued data.
 */
static void *_queue_dequeue(queue_t **rear)
{
	queue_t *front = NULL;
	void *data = NULL;

	if (!rear || !*rear)
		return (NULL);
	front = (*rear)->next;
	if (front == *rear)
		*rear = NULL;
	else
		(*rear)->next = front->next;
	data = front->data;
	free(front);
	return (data);
}

/**
 * _heap_extract_replace_root - replace the root of a heap
 *
 * @root: address of a pointer to the root of a heap
 * @node: pointer to the replacement node
 */
static void _heap_extract_replace_root(heap_t **root, heap_t *node)
{
	node->left = node != (*root)->left ? (*root)->left : NULL;
	if (node->left)
		node->left->parent = node;
	node->right = node != (*root)->right ? (*root)->right : NULL;
	if (node->right)
		node->right->parent = node;
	if (node->parent && node == node->parent->left)
		node->parent->left = NULL;
	if (node->parent && node == node->parent->right)
		node->parent->right = NULL;
	node->parent = NULL;
	free(*root);
	*root = node != *root ? node : NULL;
}

/**
 * _heap_extract_sift_down - sift the root value of a heap downward
 *
 * @root: pointer to the root of the heap to repair
 */
static void _heap_extract_sift_down(heap_t *root)
{
	heap_t *swap = root;
	heap_t *lchild = NULL;
	heap_t *rchild = NULL;
	int n = root->n;

	while (root)
	{
		lchild = root->left;
		rchild = root->right;
		if (lchild && swap->n <= lchild->n)
			swap = lchild;
		if (rchild && swap->n <= rchild->n)
			swap = rchild;
		if (swap == root)
			return;
		root->n = swap->n;
		swap->n = n;
		root = swap;
	}
}

/**
 * _heap_extract - extract the value at the root of a binary heap
 *
 * @root: address of a pointer to the root of the heap
 * @size: size of the heap
 */
/**
 *static void _heap_extract(heap_t **root, size_t size)
 *{
 *	heap_t *parent = *root;
 *	heap_t *child = NULL;
 *	size_t path = size >> 1;
 *	size_t msb = 0;
 *
 *	while ((path >> msb) > 1)
 *		msb += 1;
 *	while (msb--)
 *		parent = (path >> msb) & 1 ? parent->right : parent->left;
 *	if (size & 1)
 *	{
 *		child = parent->right;
 *		(*root)->n = parent->right->n;
 *		free(parent->right);
 *		parent->right = NULL;
 *	}
 *	else
 *	{
 *		child = parent->left;
 *		(*root)->n = parent->left->n;
 *		free(parent->left);
 *		parent->left = NULL;
 *	}
 *	_heap_extract_sift_down(*root);
 *}
 */

/**
 * heap_extract - extract the root value of a max binary heap
 *
 * @root: address of a pointer to the root of the heap
 *
 * Return: If root is NULL or the heap is empty, return 0.
 * Otherwise, return the extracted value.
 */
/**
 *int heap_extract(heap_t **root)
 *{
 *	size_t size = 0;
 *	int n = 0;
 *
 *	if (!root)
 *		return (0);
 *	size = _heap_size(*root);
 *	if (!size)
 *		return (0);
 *	n = (*root)->n;
 *	if (size > 1)
 *	{
 *		_heap_extract(root, size);
 *	}
 *	else
 *	{
 *		free(*root);
 *		*root = NULL;
 *	}
 *	return (n);
 *}
 */

/**
 * heap_extract - extract the root value of a max binary heap
 *
 * @root: address of a pointer to the root of the heap
 *
 * Return: If root is NULL or the heap is empty, return 0.
 * Otherwise, return the extracted value.
 */
int heap_extract(heap_t **root)
{
	queue_t *rear = NULL;
	heap_t *node = NULL;
	int n = 0;

	if (!root || !*root || !_queue_enqueue(&rear, *root))
		return (0);
	while (rear)
	{
		node = _queue_dequeue(&rear);
		if (node->left)
		{
			if (!_queue_enqueue(&rear, node->left))
			{
				while (rear)
					_queue_dequeue(&rear);
				return (0);
			}

		}
		if (node->right)
		{
			if (!_queue_enqueue(&rear, node->right))
			{
				while (rear)
					_queue_dequeue(&rear);
				return (0);
			}
		}
	}
	n = (*root)->n;
	_heap_extract_replace_root(root, node);
	_heap_extract_sift_down(*root);
	return (n);
}
