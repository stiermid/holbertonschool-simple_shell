#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

char *take_input();
int execute(const char *path, char const *argv[], char *const envp[]);

#endif /* SIMPLE_SHELL_H */

