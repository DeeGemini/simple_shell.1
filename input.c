#include "main.h"
#include "input.h"

/**
 * read_input - Reads a line of input from the user.
 * EXIT-FAILURE - Exit the program
 *
 * Return: A dynamically allocated string containing the user's input.
 * Returns NULL on end-of-file or error.
 */
char *read_input()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			return (NULL);
		}
		else
		{
			perror("read_input");
			free(input);
			exit(EXIT_FAILURE);
		}
	}


	if (input[read - 1] == '\n')
	{
	input[read - 1] = '\0';
	}

	return (input);
}

