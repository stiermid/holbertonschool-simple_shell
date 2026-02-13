#include "simple_shell.h"

/**
 * execute_command - executes pro
 * @args: argumets to pass execve
 * @envp: environtment
 * @argv: argument vector
 * Return: 1 on success
 */
int execute_command(char **args, char **envp, char **argv)
{
	pid_t child_pid;
	int status;

	if (args[0] == NULL)
		return (1);

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0)
		error("fork failed]n");
	else
		wait(&status);

	return (1);
}

