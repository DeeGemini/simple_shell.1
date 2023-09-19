#include "main.h"

/**
 * print_error - Print an error message to stderr.
 *
 * @format: The format string for the error message.
 * @...: Additional arguments to format.
 */
void print_error(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	fprintf(stderr, "Error: ");
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n");

	va_end(args);
	exit(EXIT_FAILURE);
}
