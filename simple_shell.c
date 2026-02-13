#define _GNU_SOURCE
#include "simple_shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * main - runs the program
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 *
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv,
		char **envp)
{
	char *command;
	char *argv2[2];

	for (;;)
	{
		printf("$ ");

		command = take_input();

		argv2[0] = command;
		argv2[1] = NULL;

		if (execve(command, argv2, envp) == -1)
			printf("%s: execve failed\n", argv[0]);
	}

	return (0);
}

