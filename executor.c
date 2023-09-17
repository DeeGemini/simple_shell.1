#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute_command - Executes a command using fork and execve.
 *
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the command.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execute_command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("execute_command");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	return (WEXITSTATUS(status));
}

/**
 * execute_exit - Executes the exit built-in command.
 *
 * This function handles the "exit" command, which terminates the shell.
 *
 * Return: Always returns 0.
 */
int execute_exit(void)
{
	exit(0);
}

/**
 * execute_env - Executes the env built-in command.
 *
 * This function handles the "env" command, which prints the
 * environment variables.
 *
 * Return: Always returns 0.
 */
int execute_env(void)
{
	char **env_ptr = environ;

	while (*env_ptr)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
	return (0);
}

/**
 * execute_cd - Executes the cd built-in command.
 * @args: An array of strings containing the command and its arguments.
 *
 * This function handles the "cd" command to change the current
 * working directory.
 *
 * Return: Always returns 0.
 */
int execute_cd(char **args)
{
	if (args[1] == NULL)
	{
		char *home_dir = getenv("HOME");

		if (home_dir)
			chdir(home_dir);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("execute_cd");
		}
	}
	return (0);
}

/**
 * execute_builtin - Executes a built-in command.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the built-in command.
 */
int execute_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (execute_exit());
	}

	else if (strcmp(args[0], "env") == 0)
	{
		return (execute_env());
	}

	else if (strcmp(args[0], "cd") == 0)
	{
		return (execute_cd(args));
	}

	return (-1);
}

