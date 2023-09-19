#include "main.h"

/**
 * redirect_output - Redirects standard output to a file.
 *
 * @filename: The name of the file to redirect output to.
 *
 * Return: 0 on success, -1 on failure.
 */
int redirect_output(const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		perror("Error opening output file");
		return (-1);
	}

	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error redirecting output");
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}

/**
 * redirect_input - Redirects standard input from a file.
 *
 * @filename: The name of the file to redirect input from.
 *
 * Return: 0 on success, -1 on failure.
 */
int redirect_input(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening input file");
		return (-1);
	}

	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error redirecting input");
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}
