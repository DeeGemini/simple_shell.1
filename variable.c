#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
* replace_variables - Replaces special variables in the input string.
*
* @input: The input string with potential variable references.
*
* Return: A new string with variables replaced.
*/

char *replace_variables(char *input)
{
	int i;
	int result_index = 0;
	char *result = malloc(strlen(input) * sizeof(char));

	if (!result)
	{
		perror("replace_variables: Allocation error");
		exit(EXIT_FAILURE);
	}

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '?')
			{
				sprintf(&result[result_index], "%d", 0);
				result_index += strlen("0");
				i++;
			}
			else if (input[i + 1] == '$')
			{
				sprintf(&result[result_index], "%d", getpid());
				result_index += strlen(&result[result_index]);
				i++;
			}
			else
			{
				result[result_index++] = input[i];
			}
		}
		else
		{
			result[result_index++] = input[i];
		}
	}
	result[result_index] = '\0';
	return (result);
}

