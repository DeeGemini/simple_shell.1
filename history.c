#include "main.h"

#define MAX_HISTORY_SIZE 1000
#define MAX_HISTORY_ENTRY_SIZE 1024

static char *history[MAX_HISTORY_SIZE];
static int history_count;

/**
 * add_to_history - Add a command to the command history.
 *
 * @command: The command to add to history.
 */
void add_to_history(const char *command)
{
	if (history_count < MAX_HISTORY_SIZE)
	{
		history[history_count] = strdup(command);

		if (history[history_count] != NULL)
		{
			history_count++;
		}
	}

	else
	{
		free(history[0]);

		for (int i = 0; i < history_count - 1; i++)
		{
			history[i] = history[i + 1];
		}
		history[history_count - 1] = strdup(command);
	}
}

/**
 * print_history - Print the command history.
 */
void print_history(void)
{
	for (int i = 0; i < history_count; i++)
	{
		printf("%d: %s\n", i + 1, history[i]);
	}
}

/**
 * free_history - Free memory allocated for command history.
 */
void free_history(void)
{
	for (int i = 0; i < history_count; i++)
	{
		free(history[i]);
	}
}

/**
 * get_history_entry - Get a specific command from history.
 *
 * @index: The index of the command to retrieve.
 *
 * Return: The command at the specified index or NULL if not found.
 */
const char *get_history_entry(int index)
{
	if (index >= 1 && index <= history_count)
	{
		return (history[index - 1]);
	}

	else
	{
		return (NULL);
	}
}
