#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/**
 * struct list_s - linked list node structure
 *
 * @c: character
 * @next: pointer to the next node
 */
typedef struct list_s
{
	char c;
	struct list_s *next;
} list_t;

int _putchar(char c);

#endif /* _HOLBERTON_H_ */
