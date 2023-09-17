#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
* execute_with_separators - Executes commands separated by ';'.
*
* @input: The input string containing commands separated by ';'.
*/

void execute_with_separators(char *input)
{
	char *token;
	char *separator = ";";
	char *input_copy = strdup(input);

	if (!input_copy)
	{
		perror("execute_with_separators: Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_copy, separator);
	while (token != NULL)
	{
		char **args = parse_input(token);

		if (args[0] != NULL)
		{
			if (execute_builtin(args) == -1)
			{
				execute_command(args);
			}
		}

		free(args);
		token = strtok(NULL, separator);
	}
	free(input_copy);
}

