#ifndef _SUBSTRING_H_
#define _SUBSTRING_H_

#include <stdbool.h>
#include <stddef.h>

#define NB_CHILDREN 26
#define CHILD_INDEX(c) ((c) - 'a')

/**
 * struct trie_s - trie structure
 *
 * @children: array of child nodes
 * @word: whether or not this is a word
 * @count: how many instances of this word
 * @left: how many instances left to find
 * @val: pointer to word
 */
typedef struct trie_s
{
	struct trie_s *children[NB_CHILDREN];
	char *word;
	size_t count;
	size_t remaining;
	bool is_word;
} trie_t;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* _SUBSTRING_H_ */
