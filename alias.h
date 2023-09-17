#ifndef ALIAS_H
#define ALIAS_H
/**
 * struct - creates a composite data structure
 *
 * Return:
 */

typedef struct
{
	const char *name;
	const char *value;
} Alias;

void execute_alias(int argc, char **args, Alias *aliases, int max_aliases);
void print_aliases(Alias *aliases, int max_aliases);
void print_alias(const char *name, Alias *aliases, int max_aliases);

#endif

