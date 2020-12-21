#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/**
 * struct binary_tree_s - binary tree node
 *
 * @n: data of the node
 * @parent: pointer to the parent node
 * @left: pointer to the left child node
 * @right: pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);

#endif /* _BINARY_TREES_H_ */
