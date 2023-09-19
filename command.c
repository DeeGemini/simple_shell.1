#include "main.h"

/**
 * execute_command - Execute a command given an array of arguments.
 * @args: Array of command arguments.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **args)
{
	if (args[0] == NULL)
		return (0);

	int background = check_background(args);

	int pipes[2] = {-1, -1};

	if (pipe(pipes) == -1)
	{
		perror("pipe");
		return (-1);
	}

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		handle_child_process(args, pipes);
	}

	else
	{
		handle_parent_process(pid, args, background);
	}

	return (0);
}

/**
 * check_background - Check if a command should run in the background.
 * @args: Array of command arguments.
 * Return: 1 if the command should run in the background, 0 otherwise.
 */
int check_background(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		if (strcmp(args[i], "&") == 0)
		{
			args[i] = NULL;
			return (1);
		}
		i++;
	}

	return (0);
}

/**
 * handle_child_process - Logic for the child process.
 * @args: Array of command arguments.
 * @pipes: Array of pipe file descriptors.
 */
void handle_child_process(char **args, int pipes[2])
{
	if (pipes[0] != -1)
	{
		close(pipes[0]);
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[1]);
	}

	if (execute_builtin(args) == -1)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}

/**
 * handle_parent_process - Logic for the parent process.
 * @pid: Child process ID.
 * @args: Array of command arguments.
 * @background: 1 if the command should run in the background, 0 otherwise.
 */
void handle_parent_process(pid_t pid, char **args, int background)
{
	if (background)
	{
		printf("[%d] %s\n", pid, args[0]);
	}

	else
	{
		int status;

		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
