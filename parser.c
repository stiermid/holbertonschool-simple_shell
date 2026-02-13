#include "simple_shell.h"

/**
 * split_line - a TODO
 * @line: line
 * Return: list of arguments
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		exit(EXIT_FAILURE);

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;

	return (tokens);
}

/**
 * free_args - frees arguments
 * @args: arguments to free
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}

