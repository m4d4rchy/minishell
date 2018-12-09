/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** env.c
*/

#include "my.h"

int my_envparser(char **command, t_environ *envir)
{
	int(*pof[4])(char **command, t_environ *envir) = {my_env, my_setenv, my_unsetenv};
	char *cpcommand[4] = {"env", "setenv", "unsetenv", NULL};
	int i = 0;
	int ret = 0;

	while (cpcommand[i] != NULL && command[0] != NULL) {
		if (my_strcmp(command[0], cpcommand[i]) == 0)
			ret = pof[i](command, envir);
		i = i + 1;
	}
	return (ret);
}

int my_env(char **input, t_environ *envir)
{
	(void)input;
	int nb = 0;

	while (envir->env[nb] != NULL) {
		my_printf("%s\n", envir->env[nb]);
		nb = nb + 1;
	}
	return (1);
}

int my_setenv(char **input, t_environ *envir)
{
	int len = 0;

	if (input[1] == NULL)
		my_env(input, envir);
	else if (input[1][0] >= '0' && input[1][0] <= '9') {
		my_printf("setenv: Variable name must contain alphanumeric characters.");
	}
	else if (input[1] != NULL) {
		my_printf("test\n");
		len = my_argvlen(envir->env);
		envir->env = my_realloc_array(envir->env, 1);
		envir->env[len] = my_strdup(input[1]);
		envir->env[len] = my_strcat(envir->env[len], "=");
		if (input[2] != NULL)
			envir->env[len] = my_strcat(envir->env[len], input[2]);
	}
	return (1);
}

int my_unsetenv(char **input, t_environ *envir)
{
	int i = 0;
	(void)input;

	while (envir->env[i] != NULL) {
		i = i + 1;
	}
	return (1);
}
