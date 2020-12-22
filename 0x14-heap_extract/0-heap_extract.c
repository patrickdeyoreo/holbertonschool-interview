#include <stdlib.h>

#include "binary_trees.h"

/**
 * _heap_size - measure the size of a binary heap
 *
 * @root: pointer to the root of the heap to measure
 *
 * Return: size of the heap pointed to by root
 */
static size_t _heap_size(heap_t *root)
{
	return (root ? _heap_size(root->left) + _heap_size(root->right) + 1 : 0);
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
static void _heap_extract(heap_t **root, size_t size)
{
	heap_t *parent = *root;
	heap_t *child = NULL;
	size_t path = size >> 1;
	size_t msb = 0;

	while ((path >> msb) > 1)
		msb += 1;
	while (msb--)
		parent = (path >> msb) & 1 ? parent->right : parent->left;
	if (size & 1)
	{
		child = parent->right;
		parent->right = NULL;
	}
	else
	{
		child = parent->left;
		parent->left = NULL;
	}
	child->left = child != (*root)->left ? (*root)->left : NULL;
	if (child->left)
		child->left->parent = child;
	child->right = child != (*root)->right ? (*root)->right : NULL;
	if (child->right)
		child->right->parent = child;
	child->parent = NULL;
	free(*root);
	*root = child != *root ? child : NULL;
	_heap_extract_sift_down(*root);
}

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
	size_t size = 0;
	int n = 0;

	if (!root)
		return (0);
	size = _heap_size(*root);
	if (!size)
		return (0);
	n = (*root)->n;
	_heap_extract(root, size);
	return (n);
}
