#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "input.h"

/**
* print_prompt - Prints the shell prompt.
*/

void print_prompt(void)
{
	printf("YourShell> ");
}

/**
* read_input - Reads a line of input from the user.
*
* Return: A dynamically allocated string containing the input.
*/
/*
char *read_input()
{
	char *input = NULL;
	size_t bufsize = 0;

	getline(&input, &bufsize, stdin);
	return (input);
}
*/
/**
 * main - introduction
 *
 * Return: 0 sucess
 */
/*
int main(void)
{
	char *userInput = read_input();

	printf("User input: %s", userInput);

	free(userInput);

	return (0);
}
*/
/**
* trim_whitespace - Removes leading and trailing whitespace from a string.
*
* @str: The string to trim.
*
* Return: A new dynamically allocated string with whitespace removed.
*/

char *trim_whitespace(char *str)
{
	char *end = str + strlen(str) - 1;

	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		str++;
	}

	if (*str == '\0')
	{
		return (str);
	}

	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}
	*(end + 1) = '\0';
	return (str);
}

/**
* count_tokens - Counts the number of tokens in a string using a delimiter.
*
* @input: The input string.
* @delimiter: The delimiter used to split the string.
*
* Return: The number of tokens.
*/

int count_tokens(char *input, char *delimiter)
{
	int count = 0;
	char *token = strtok(input, delimiter);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	return (count);
}

