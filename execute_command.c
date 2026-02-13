#include "simple_shell.h"

/**
 * execute_command - fork and execute a program
 * @args: argumets to pass execve
 * @envp: environtment
 * @argv: main argument vector
 *
 * Return: 1 on success
 */
int execute_command(char **args, char **envp, char **argv)
{
	pid_t child_pid;
	int status;
	char *path = NULL;


	if (args == NULL || args[0] == NULL)
		return (1);

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (is_valid_command(args[0]))
			path = strdup(args[0]);
	}
	else
		path = get_command_path(args[0]);


	if (path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(path, args, envp) == -1)
		{
			perror(argv[0]);
			free(path);
			_exit(127);
		}
	}
	else if (child_pid < 0)
	{
		perror("fork failed\n");
		free(path);
	}
	else
	{
		wait(&status);
		free(path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	free(path);
	return (1);
}

/**
 * get_command_path - checks for a command in PATH variable
 * @command: command to look up
 *
 * Return: path if found, otherwise NULL
 */
char *get_command_path(char *command)
{
	const char *path_env = _getenv("PATH");
	char *path, *token, *full_path;

	if (!path_env || !command)
		return (NULL);

	path = strdup(path_env);
	token = strtok(path, ":");

	if (!path)
		return (NULL);

	while (token != NULL)
	{
		/* allocate space: token len + '/' + command len + null terminator */
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
			break;

		sprintf(full_path, "%s/%s", token, command);

		if (is_valid_command(full_path))
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * is_valid_command - checks for the path if it is a valid command or not
 * @path: path to check
 *
 * Return: 1 on success, 0 on failure
 */
int is_valid_command(char *path)
{
	struct stat st;

	if (path == NULL)
		return (0);

	if (stat(path, &st) == 0 && (st.st_mode & S_IXUSR))
		return (1);

	return (0);
}
