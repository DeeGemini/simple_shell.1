#include "main.h"

/**
 * allocate_mem - Allocate memory with error handling.
 * @size: The size of memory to allocate.
 *
 * This function allocates memory using malloc and performs
 * error handling if the allocation fails.
 *
 * Return: A pointer to the allocated memory.
 */
void *allocate_mem(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	return (ptr);
}
