#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: integer stored in the node
 * @parent: pointer to the parent node
 * @left: pointer to the left child node
 * @right: pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s heap_t;

/**
 * struct list_s - Singly-linked list node
 *
 * @root: pointer to the root node of a subtree
 * @next: pointer to the next list node
 */
typedef struct list_s
{
	binary_tree_t *root;
	struct list_s *next;
} list_t;
typedef struct list_s queue_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */
