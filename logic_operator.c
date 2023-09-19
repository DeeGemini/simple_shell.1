#include "main.h"

/**
 * execute_logical_operator - Execute logical operators like && and ||
 * @left_command: The left-hand command to execute
 * @right_command: The right-hand command to execute
 * @operator_type: The type of logical operator (0 for &&, 1 for ||)
 * Return: 1 on success, 0 on failure.
 */
int execute_logical_operator(char *left_command, char *right_command,
	int operator_type)
{
	int status;

	if (execute_command(left_command) == 0)
	{
		if (operator_type == 0)
		{
			if (execute_command(right_command) == 0)
			return (1);

			else
			return (0);
		}

		else
		{
			if (execute_command(right_command) == 0)
			return (0);

			else
			return (1);
		}
	}

	return (0);
}
