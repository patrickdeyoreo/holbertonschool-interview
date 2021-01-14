#include <stdlib.h>

#include "holberton.h"

/**
 * list_create - create a list node
 *
 * @c: character to store in the node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
static list_t *list_create(char c)
{
	list_t *list = malloc(sizeof(*list));

	if (list)
	{
		list->c = c;
		list->next = NULL;
	}
	return (list);
}

/**
 * list_delete - delete a list
 *
 * @list: pointer to the start of a list
 */
static void list_delete(list_t *list)
{
	list_t *temp = NULL;

	while ((temp = list))
	{
		list = list->next;
		free(temp);
	}
}

/**
 * list_print - print a list
 *
 * @list: pointer to the start of a list
 */
static void list_print(list_t *list)
{
	while (list)
	{
		_putchar(list->c);
		list = list->next;
	}
	_putchar('\n');
}

/**
 * _list_reverse - reverse a list (subroutine)
 *
 * @list: address of a pointer to the start of a list
 * @node: pointer to the current node being reversed
 *
 * Return: address of the 'next' pointer of the last reversed node
 */
static list_t **_list_reverse(list_t **list, list_t *node)
{
	if (node->next)
	{
		list = _list_reverse(list, node->next);
		node->next = NULL;
	}
	*list = node;
	return (&node->next);
}

/**
 * list_reverse - reverse a list
 *
 * @list: address of a pointer to the start of a list
 *
 * Return: pointer to the start of the reversed list
 */
static list_t *list_reverse(list_t **list)
{
	if (*list)
		_list_reverse(list, *list);
	return (*list);
}

/**
 * _isdigit - determine if a character is a digit
 *
 * @c: the character to check
 *
 * Return: If c is a digit, return 1.
 * Otherwise, return 0.
 */
static int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _isnonneg - determine if a string is a nonnegative integer
 *
 * @s: the string to check
 *
 * Return: If s contains only digits, return 1.
 * Otherwise, return 0.
 */
static int _isnonneg(const char *s)
{
	if (!*s)
		return (0);
	while (*s)
	{
		if (!_isdigit(*s++))
			return (0);
	}
	return (1);
}

/**
 * _puts - write a string to stdout
 *
 * @s: the string to print
 *
 * Return: On error, return -1 and set errno appropriately.
 * Otherwise, return the number of characters written.
 */
static size_t _puts(const char *s)
{
	size_t n = 0;

	while (*s)
		n += _putchar(*s++);
	n += _putchar('\n');
	return (n);
}

/**
 * _error - print an error and exit
 *
 * @status: status with which to exit
 * @message: error message to print
 */
static void _error(int status, const char *message)
{
	if (message)
		_puts(message);
	if (status)
		exit(status);
}

/**
 * _strlen - measure the length of a string
 *
 * @s: the string to measure
 *
 * Return: length of s
 */
static size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s++)
		len += 1;
	return (len);
}

/**
 * mul - multiply two integers
 *
 * @a: string representation of an integer
 * @b: string representation of an integer
 *
 * Return: pointer to the resulting list
 */
static list_t *mul(const char *a, const char *b)
{
	list_t *result = NULL;
	list_t **digit = &result;
	size_t a_len = _strlen(a);
	size_t b_len = _strlen(b);
	size_t a_index = 0;
	size_t b_index = 0;
	size_t digit_skip = 0;
	unsigned int e = 0;
	unsigned int n = 0;
	unsigned int m = 0;
	unsigned int o = 0;

	for (a_index = a_len - 1; a_index < a_len; a_index -= 1)
	{
		n = a[a_index] - '0';
		digit = &result;
		digit_skip = e;
		while (digit_skip--)
			digit = &(*digit)->next;
		for (b_index = b_len - 1; b_index < b_len; b_index -= 1)
		{
			m = b[b_index] - '0';
			o += n * m;
			if (*digit)
				o += (*digit)->c - '0';
			if (*digit)
				(*digit)->c = o % 10 + '0';
			else
				*digit = list_create(o % 10 + '0');
			digit = &(*digit)->next;
			o /= 10;
		}
		if (o)
			*digit = list_create(o % 10 + '0');
		o /= 10;
		e += 1;
	}
	return (result);
}

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Usage: mul num1 num2
 *
 * Return: If the number of arguments is incorrect or either num1 or num2
 * is composed of non-digit characters, exit with status 98.
 * Otherwise, return EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	list_t *result = NULL;
	list_t *output = NULL;

	if (argc != 3 || !_isnonneg(argv[1]) || !_isnonneg(argv[2]))
		_error(98, "Error");
	result = mul(argv[1], argv[2]);
	output = list_reverse(&result);
	while (output && output->c == '0')
		output = output->next;
	if (output)
		list_print(output);
	else
		_puts("0");
	list_delete(result);
	return (EXIT_SUCCESS);
}
