#include "holberton.h"

/**
 * wildcmp - compare a string with a pattern
 *
 * @s1: string to compare
 * @s2: pattern to compare
 *
 * Description: @pattern may contain the wildcard character, '*', which will be
 * considered to match any string, including the empty string.
 *
 * Return: If @string matches @pattern, return 1. Otherwise, return 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
