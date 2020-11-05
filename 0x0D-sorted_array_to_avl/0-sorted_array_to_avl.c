#include "binary_trees.h"

/**
 * avl_node - create a new AVL tree node
 *
 * @n: value to store in the new node
 * @parent: pointer to the parent of the node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
static avl_t *avl_node(int n, avl_t *parent)
{
	avl_t *node = malloc(sizeof(*node));

	if (node)
	{
		node->n = n;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}

/**
 * _sorted_array_to_avl - build an AVL tree from a sorted array
 *
 * @array: sorted array
 * @size: size of array
 * @parent: pointer to the parent node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
static avl_t *_sorted_array_to_avl(int *array, size_t size, avl_t *parent)
{
	avl_t *node = size ? avl_node(array[(size - 1) / 2], parent) : NULL;

	if (node)
	{
		node->left = _sorted_array_to_avl(array, (size - 1) / 2, node);
		node->right = _sorted_array_to_avl(array + (size + 1) / 2, size / 2, node);
	}
	return (node);
}

/**
 * sorted_array_to_avl - build an AVL tree from a sorted array
 *
 * @array: sorted array
 * @size: size of array
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the root of the tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (array && size ? _sorted_array_to_avl(array, size, NULL) : NULL);
}
