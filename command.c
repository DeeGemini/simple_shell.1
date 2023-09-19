#include "main.h"

/**
 * execute_command - Execute a command given an array of arguments.
 * @args: Array of command arguments.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	int background = 0;
	int pipes[2] = {-1, -1};

	if (args[0] == NULL)
	return (0);

	int i = 0;
	
	while (args[i] != NULL)
	{
		if (strcmp(args[i], "&") == 0)
		{
			background = 1;
			args[i] = NULL; 
			break;
		}
		i++;
	}

	if (pipe(pipes) == -1)
	{
		perror("pipe");
		return (-1);
	}

	pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	
	if (pid == 0)
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
	
	else
	{
		if (background)
		{
			printf("[%d] %s\n", pid, args[0]);
		}
		else
		{
			do
			{
				waitpid(pid, &status, WUNTRACED);
			}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		return (0);
	}

	return (-1); 
}
