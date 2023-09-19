#include "main.h"

/**
 * handle_signal - Handles the SIGINT (Ctrl+C) signal.
 *
 * @signal: The signal number.
 */
void handle_signal(int signal)
{
	(void)signal;

	printf("\nSIGINT (Ctrl+C) received. Use 'exit' to quit the shell.\n");

	print_prompt();
	fflush(stdout);
}

/**
 * setup_signal_handler - Sets up a signal handler for SIGINT (Ctrl+C).
 *
 * Return: 0 on success, -1 on failure.
 */
int setup_signal_handler(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;

	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("Error setting up signal handler");
		return (-1);
	}

	return (0);
}
