#include <unistd.h>
#include "main.h"

/**
 * execute_exit - Implements the exit built-in command.
 *
 * Return: The exit status for the shell.
 */
int execute_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * execute_env - Implements the env built-in command.
 *
 * Return: Always returns 0.
 */
int execute_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}

/**
 * execute_cd - Implements the cd built-in command.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("execute_cd");
			return (-1);
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("execute_cd");
			return (-1);
		}
	}

	return (0);
}

