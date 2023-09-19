#include "main.h"

/**
 * str_starts_with - Check if a string starts with a prefix.
 *
 * @str: The string to check.
 * @prefix: The prefix to compare.
 *
 * Return: 1 if the string starts with the prefix, 0 otherwise.
 */
int str_starts_with(const char *str, const char *prefix)
{
	size_t len_str = strlen(str);
	size_t len_prefix = strlen(prefix);

	if (len_str < len_prefix)
	{
		return (0);
	}

	return (strncmp(str, prefix, len_prefix) == 0);
}

/**
 * str_trim - Trim leading and trailing whitespace from a string.
 *
 * @str: The string to trim.
 *
 * Return: A pointer to the trimmed string.
 */
char *str_trim(char *str)
{
	char *end;

	while (isspace(*str))
	{
		str++;
	}

	end = str + strlen(str) - 1;

	while (end > str && isspace(*end))
	{
		end--;
	}

	*(end + 1) = '\0';

	return (str);
}
