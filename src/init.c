/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** init.c
*/

#include "my.h"

int my_init_env(t_environ *envir, char **environ)
{
	int i = 0;
	(void)envir;

	envir->env = malloc(sizeof(char *) * (my_argvlen(environ) + 1));
	while (environ[i] != NULL) {
		envir->env[i] = my_strdup(environ[i]);
		i = i + 1;
	}
	envir->env[i] = NULL;
	return (0);
}
