#define _GNU_SOURCE
#include "simple_shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>

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
	char *command;
	char *argv2[2];
	pid_t child_pid;
	int status;

	for (;;)
	{
		printf("$ ");
		fflush(stdout);

		command = take_input();

		if (command == NULL)
			return (0);

		argv2[0] = command;
		argv2[1] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			printf("fork failed\n");
			continue;
		}

		if (child_pid == 0)
		{
			if (execve(command, argv2, envp) == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}

	return (0);
}

