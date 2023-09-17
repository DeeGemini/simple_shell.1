#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* remove_comments - Removes comments from the input string.
*
* @input: The input string potentially containing comments.
*
* Return: A new string with comments removed.
*/

char *remove_comments(char *input)
{
	int i;
	int result_index = 0;
	int inside_quote = 0;
	char *result = malloc(strlen(input) * sizeof(char));

	if (!result)
	{
		perror("remove_comments: Allocation error");
		exit(EXIT_FAILURE);
	}

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '"')
		{
			inside_quote = !inside_quote;
			result[result_index++] = input[i];
		}
		else if (!inside_quote && input[i] == '#')
		{
			break;
		}
		else
		{
			result[result_index++] = input[i];
		}
	}
	result[result_index] = '\0';
	return (result);
}

