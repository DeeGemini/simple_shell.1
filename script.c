#include "main.h"

#define MAX_SCRIPT_SIZE 1000
#define MAX_SCRIPT_LINE_SIZE 1024

static char *script[MAX_SCRIPT_SIZE];
static int script_count;

/**
 * load_script - Load a script from a file into memory.
 *
 * @filename: The name of the script file to load.
 *
 * Return: 0 on success, -1 on failure.
 */
int load_script(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Error opening script file");
		return (-1);
	}

	char line[MAX_SCRIPT_LINE_SIZE];

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (script_count < MAX_SCRIPT_SIZE)
		{
			script[script_count] = strdup(line);

			if (script[script_count] != NULL)
			{
				script_count++;
			}
		}

		else
		{
			break;
		}
	}

	fclose(file);

	return (0);
}

/**
 * execute_script - Execute the loaded script.
 */
void execute_script(void)
{
	for (int i = 0; i < script_count; i++)
	{
		printf("Executing: %s", script[i]);
	}
}

/**
 * free_script - Free memory allocated for the script.
 */
void free_script(void)
{
	for (int i = 0; i < script_count; i++)
	{
		free(script[i]);
	}
}
