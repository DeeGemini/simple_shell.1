#include "main.h"

/**
 * process_file - Process commands from a file.
 *
 * @filename: The name of the file to process.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int process_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line[read - 1] = '\0';

		char **commands = parse_input(line);

		for (int i = 0; commands[i] != NULL; i++)
		{
			int status = execute_command(commands[i]);

			if (status != EXIT_SUCCESS)
			{
				fprintf(stderr, "Command failed: %s\n", commands[i]);

				overall_status = EXIT_FAILURE;
			}
		}

		free(commands);
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
