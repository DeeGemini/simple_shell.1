#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alias.h"

/**
 * execute_alias - implements the alias builtin command
 *
 * @argc: the number of arguments
 * @args: array of strings containing the command and its argument
 * @aliases: ...
 * @max_aliases: ...
 */
void execute_alias(int argc, char **args, Alias *aliases, int max_aliases)
{
	int i;
	
	(void)argc;

	for (i = 0; i < max_aliases && aliases[i].name; i++)
	{
		if (strcmp(aliases[i].name, args[1]) == 0)
		{
			aliases[i].value = args[2];
			break;
		}
	}
	if (i == max_aliases)
	{
		fprintf(stderr, "Max number of aliases reached\n");
	}
}

/**
 * print_aliases - prints all defined aliases
 *
 * @aliases: ....
 * @max_aliases: ....
 *
 */
void print_aliases(Alias *aliases, int max_aliases)
{
	int i;

	for (i = 0; i < max_aliases && aliases[i].name; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * print_alias - prints the vlaue of a specified alias
 *
 * @name: the name of the alias to print
 * @aliases: ....
 * @max_aliases: ...
 */
void print_alias(const char *name, Alias *aliases, int max_aliases)
{
	int i;

	for (i = 0; i < max_aliases && aliases[i].name; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			return;
		}
	}
	fprintf(stderr, "Alias not found: %s\n", name);
}

