#include "palindrome.h"

/**
 * is_palindrome - check if a base-10 number is palindromic
 * @n: the number to check
 * Return: 1 if n is palindromic, otherwise 0
 */
int is_palindrome(unsigned long int n)
{
	unsigned long int p = n;
	unsigned long int q = 0;

	while (n)
	{
		q *= 10;
		q += n % 10;
		n /= 10;
	}
	return (p == q);
}
