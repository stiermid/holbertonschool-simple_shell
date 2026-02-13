#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

char *read_line(void);
char **split_line(char *line);
int execute_command(char **args, char **envp, char **argv);
void free_args(char **args);

#endif /* SIMPLE_SHELL_H */

