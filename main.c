#include "main.h"
#include "input.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024


/*
 * prompt_user - Display the command prompt
 *
 */
void prompt_user(void)
{
	printf("$ ");
}

/**
 * main - Entry point for the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (argc == 1)
	{
		handle_interactive_mode();
	}
	else if (argc == 2)
	{
		handle_file_mode(argv[1]);
	}

	return (EXIT_SUCCESS);
}

/**
 * handle_interactive_mode - Handles the interactive mode of the shell.
 */
void handle_interactive_mode(void)
{
	char *input;
	char **commands;
	char **args;
	int status;
	int i, j;

	while (1)
	{
		prompt_user();
		input = read_input();

		if (input == NULL)
		{
			printf("\n");
			break;
		}

		commands = parse_input(input);

	for (i = 0; commands[i] != NULL; i++)
	{
		args = parse_input(commands[i]);
		status = execute_command(args);

		for (j = 0; args[j] != NULL; j++)
		{
			free(args[j]);
		}
		free(args);

		printf("Executed command: %s\n", commands[i]);
		printf("Exit status: %d\n", status);
	}
	free(commands);
	free(input);
	}
}

/**
 * handle_file_mode - Handles the file mode of the shell.
 * @filename: The name of the file to read commands from.
 */
void handle_file_mode(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	{

		size_t len = 0;
		ssize_t read;
		char *line;
		char **commands;
		char **args;
		int status;
		int i, j;

		while ((read = getline(&line, &len, file)) != -1)
		{
			line[read - 1] = '\0';
			commands = parse_input(line);

			for (i = 0; commands[i] != NULL; i++)
			{
				args = parse_input(commands[i]);
				status = execute_command(args);

				for (j = 0; args[j] != NULL; j++)
				{
					free(args[j]);
				}
				free(args);
				printf("Executed command: %s\n", commands[i]);
				printf("Exit status: %d\n", status);
			}
			free(commands);
		}

		free(line);
	}

	fclose(file);
}
