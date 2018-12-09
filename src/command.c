/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** command.c
*/

#include "my.h"

int my_main_excve(char **input, char **allpath, t_environ *envir)
{
	char **path = NULL;
	int err = -1;
	int nb = 0;

	while (allpath[nb] != NULL) {
		path = my_command_check(input, allpath[nb]);
		err = my_excve(path, envir);
		nb = nb + 1;
	}
	if (err == -1) {
		write(1, input[0], my_strlen(input[0]));
		write(1, ": Command not found\n", 20);
		exit(1);
	}
	free_array(path);
	return (0);
}

int my_excve(char **path, t_environ *envir)
{
	char *args[3];
	int err = 0;

	args[0] = my_strdup(path[0]);
	if (path[1] != NULL)
		args[1] = my_strdup(path[1]);
	else
		args[1] = NULL;
	args[2] = NULL;
	err = execve(args[0], args, envir->env);
	return (err);
}

int my_parser(char **command, t_environ *envir)
{
	int (*pof[7])(char **command, t_environ *envir) = {my_chdir, my_exit, my_clear};
	char *cpcommand[4] = {"cd", "exit", "clear", NULL};
	int i = 0;
	int res = 0;
	(void)command;

	while (cpcommand[i] != NULL && command[0] != NULL) {
		if (my_strcmp(command[0], cpcommand[i]) == 0)
			res = pof[i](command, envir);
		i = i + 1;
	}
	return (res);
}

char **my_command_check(char **command, char *path)
{
	char **tmp = malloc(sizeof(char *) * 2);

	tmp[0] = NULL;
	tmp[1] = NULL;
	if (command[0] != NULL) {
		tmp[0] = my_strcat(path, command[0]);
		if (command[1] != NULL)
			tmp[1] = my_strdup(command[1]);
		else
			tmp[1] = NULL;
	}
	return (tmp);
}
