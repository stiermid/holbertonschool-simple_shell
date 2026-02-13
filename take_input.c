#include "simple_shell.h"

/**
 * read_line - reads a line of input from standart input
 *
 * Return: a pinter to the string or NULL if an error occurs or EOF is reached
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

