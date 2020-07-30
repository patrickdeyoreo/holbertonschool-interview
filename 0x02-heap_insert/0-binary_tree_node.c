#include "binary_trees.h"

/**
 * binary_tree_node - create and initialize a new binary tree node
 * @parent: address of the parent of the new node
 * @value: integer to store in the new node
 * Return: On failure return NULL. Otherwise return a pointer to the node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (new)
	{
		new->n = value;
		new->parent = parent;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
