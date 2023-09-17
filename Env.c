#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * execute_setenv - implements the setenv builtin command
 *
 * @args: array of string containing the command and its arguments
 */

void execute_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "usage: setenv VARIABLE VALUE\n");
		return;
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("execute_setenv");
	}
}

/**
 * execute_unsetenv - impements the unsetenv builtin command
 *
 * @args: array of string containing the command and its arguments
 */

void execute_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "usage:unsetenv VARIABLE VALUE\n");
		return;
	}
	if (unsetenv(args[1]) == -1)
	{
		perror("execute_unsetenv");
	}
}

