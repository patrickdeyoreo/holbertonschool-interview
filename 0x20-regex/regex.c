#include "regex.h"

/**
 * regex_match - match a string against a regular expression
 *
 * Description:
 * '.' matches any single character.
 * '*' matches zero or more of the preceding character.
 *
 * @str: string to match
 * @pattern: regular expression to match against
 *
 * Return: If @str matches @pattern, return 1.
 * Otherwise, return 0.
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str)
	{
		if (*pattern)
		{
			return (pattern[1] == '*' &&
				regex_match(str, pattern + 2));
		}
		else
		{
			return (1);
		}
	}
	if (pattern[1] == '*')
	{
		if (*pattern == '.' || *str == *pattern)
		{
			return (regex_match(str + 1, pattern) ||
				regex_match(str, pattern + 2));
		}
		else
		{
			return (regex_match(str, pattern + 2));
		}
	}
	if (*pattern == '.' || *pattern == *str)
	{
		return (regex_match(str + 1, pattern + 1));
	}
	else
	{
		return (0);
	}
}
