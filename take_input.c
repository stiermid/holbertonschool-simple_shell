#include "simple_shell.h"

/**
 * take_input - receives input
 * Return: parsed input
 */
char *take_input()
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&buffer, &len, stdin);
	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}

	if (read > 0 && buffer[read - 1] == '\n')
		buffer[read - 1] = '\0';

	return (buffer);
}

