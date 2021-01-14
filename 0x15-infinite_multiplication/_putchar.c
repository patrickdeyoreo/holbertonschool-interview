#include <unistd.h>

/**
 * _putchar - write a character to stdout
 * @c: the character to print
 *
 * Return: On error, return -1 and set errno appropriately.
 * Otherwise, return 0.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
