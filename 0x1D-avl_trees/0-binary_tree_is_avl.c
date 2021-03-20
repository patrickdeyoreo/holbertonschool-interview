#include <limits.h>

#include "binary_trees.h"

/**
 * _binary_tree_is_bst - determine if a binary tree is a BST
 *
 * @tree: pointer to the root of the tree
 * @lower: lower bound
 * @upper: upper bound
 *
 * Return: If tree is not a BST, return 0.
 * Otherwise, return 1.
 */
static int _binary_tree_is_bst(const binary_tree_t *tree, int lower, int upper)
{
	if (tree)
	{
		if (tree->n > lower && tree->n < upper)
		{
			return (_binary_tree_is_bst(
					tree->left, lower, tree->n) &&
				_binary_tree_is_bst(
					tree->right, tree->n, upper));
		}
		return (0);
	}
	return (1);
}

/**
 * binary_tree_is_bst - determine if a binary tree is a BST
 *
 * @tree: pointer to the root of the tree
 *
 * Return: If tree is NULL or is not a BST, return 0.
 * Otherwise, return 1.
 */
static int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree)
	{
		return (_binary_tree_is_bst(
				tree->left, INT_MIN, tree->n) &&
			_binary_tree_is_bst(
				tree->right, tree->n, INT_MAX));
	}
	return (0);
}

/**
 * binary_tree_height - measure the height of a binary tree
 *
 * @tree: pointer to the root of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the height of the tree.
 */
static size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lhs = 0;
	size_t rhs = 0;

	if (tree)
	{
		lhs = binary_tree_height(tree->left);
		rhs = binary_tree_height(tree->right);
		return ((lhs > rhs ? lhs : rhs) + 1);
	}
	return (0);
}

/**
 * binary_tree_is_balanced - check if a binary tree is balanced
 *
 * @tree: pointer to the root of the tree
 *
 * Return: If tree is not balanced, return 0.
 * Otherwise, return 1.
 */
static int binary_tree_is_balanced(const binary_tree_t *tree)
{
	size_t lhs = 0;
	size_t rhs = 0;
	size_t balance = 0;

	if (tree)
	{
		lhs = binary_tree_height(tree->left);
		rhs = binary_tree_height(tree->right);
		balance = lhs > rhs ? (lhs - rhs) : (rhs - lhs);
		if (balance <= 1)
		{
			return (binary_tree_is_balanced(tree->left) &&
				binary_tree_is_balanced(tree->right));
		}
		return (0);
	}
	return (1);
}

/**
 * binary_tree_is_avl - check if a binary tree is an AVL tree
 *
 * @tree: pointer to the root of the tree
 *
 * Return: If tree is NULL or is not an AVL tree, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_is_bst(tree) &&
			binary_tree_is_balanced(tree));
	}
	return (0);
}
