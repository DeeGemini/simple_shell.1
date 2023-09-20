#include "main.h"

/**
 * parse_input - Parses user input into an array of commands and arguments.
 * @input: The user's input string.
 *
 * Return: An array of strings representing commands and arguments.
 */
char handle_file_mode(const char *filename)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("parse_input: Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok((char *)input, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

	if (position >= bufsize)
	{
		bufsize += 64;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			perror("parse_input: Reallocation error");
			exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, " ");
	}
	tokens[position] = NULL;

	return (tokens);
}

