#include "simple_shell.h"

/**
 * _getenv - getenv
 * @name: name of the variable
 *
 * Return: string
 */
char *_getenv(const char *name)
{
	int len = strlen(name);
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}

	return (NULL);
}

