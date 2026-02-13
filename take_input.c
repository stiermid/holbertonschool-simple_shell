#include "simple_shell.h"

/**
 * read_line - receives input
 * Return: parsed input
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}

	return (buffer);
}

