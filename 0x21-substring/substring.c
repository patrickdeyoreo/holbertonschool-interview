#include <stdlib.h>
#include <string.h>

#include "substring.h"

/**
 * trie_build - fill a trie with words
 *
 * @root: pointer to the root of the trie
 * @words: pointer to the array of words
 * @nb_words: number of words
 * @nodes: array of trie nodes to populate
 */
static void trie_build(
	trie_t *root, char const **words, int nb_words, trie_t **nodes
)
{
	char const *str = NULL;
	trie_t *node = NULL;
	int word_index = 0;

	while (word_index < nb_words)
	{
		node = root;
		for (str = words[word_index]; *str; str++)
		{
			if (!node->children[CHILD_INDEX(*str)])
			{
				node->children[CHILD_INDEX(*str)] = calloc(1, sizeof(trie_t));
				if (!node->children[CHILD_INDEX(*str)])
					exit(1);
			}
			node = node->children[CHILD_INDEX(*str)];
		}
		node->word = (char *)words[word_index];
		node->count++;
		node->remaining++;
		node->is_word = true;
		nodes[word_index] = node;
		word_index += 1;
	}
}

/**
 * trie_search - search a trie for a word
 *
 * @node: root of trie to search
 * @str: string to find
 * @k: characters of @str to find
 * @memo: memoization array
 * @j: index in @memo
 *
 * Return: If @word is found, return 1. Otherwise, return 0.
 */
static int trie_search(trie_t *node, char *str, int k, trie_t **memo, int j)
{
	while (k)
	{
		if (!node->children[CHILD_INDEX(*str)])
			return (0);
		node = node->children[CHILD_INDEX(*str)];
		str += 1;
		k -= 1;
	}
	memo[j] = node;
	if (node->remaining-- > 0)
	{
		return (1);
	}
	return (0);
}

/**
 * trie_delete - delete a trie
 *
 * @root: pointer to the root of a trie
 */
static void trie_delete(trie_t *root)
{
	int child_index = 0;

	while (child_index < NB_CHILDREN)
	{
		if (root->children[child_index])
			trie_delete(root->children[child_index]);
		child_index += 1;
	}
	free(root);
}

/**
 * find_substring - find all substrings containing all words in a given list
 *
 * @s: string to search
 * @words: words to find
 * @nb_words: number of elements in @words
 * @n: address at which to store the number of elements in the returned array
 *
 * Return: If no substring is found, return NULL.  Otherwise, allocate and
 * return an array containing the starting index of each substring.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0, j, k, slen, matches;
	trie_t *root, **nodes, **memo;
	int *indices;

	*n = 0;
	slen = strlen(s);
	k = strlen(words[0]);
	indices = calloc(slen, sizeof(int));
	root = calloc(1, sizeof(trie_t));
	nodes = calloc(nb_words, sizeof(*nodes));
	memo = calloc(slen, sizeof(*memo));
	if (!indices || !root || !nodes || !memo)
		exit(1);
	trie_build(root, words, nb_words, nodes);

	for (i = 0; i < slen; i++)
	{
		matches = 0;
		for (j = i; j <= slen - k; j += k)
		{
			if ((memo[j] && memo[j]->remaining-- > 0) ||
				trie_search(root, (char *)s + j, k, memo, j))
			{
				if (++matches == nb_words)
				{
					indices[*n] = i;
					*n += 1;
					break;
				}
			}
			else
				break;
		}
		for (j = 0; j < nb_words; j++)
			nodes[j]->remaining = nodes[j]->count;
	}
	trie_delete(root), free(nodes), free(memo);
	if (*n == 0)
		indices = (free(indices), NULL);
	return (indices);
}
