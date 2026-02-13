#define _GNU_SOURCE
#include "simple_shell.h"

/**
 * main - runs the program
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 *
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char **argv,	char **envp)
{
	char *line;
	char **args;
	int status = 0;

	for (;;)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		line = read_line();
		if (line == NULL)
			break;

		args = split_line(line);
		if (args && args[0])
			status = execute_command(args, envp, argv);

		free(line);
		free_args(args);
	}

	return (status);
}

