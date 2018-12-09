/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** chdir.c
*/

#include "my.h"

int my_set_old_pwd(t_environ *envir)
{
	int array = old_find_array(envir);
	char cwd[1000];
	char old[255] = "OLDPWD=";
	char *tmp = NULL;

	getcwd(cwd, 1000);
	tmp = my_strcat(old, cwd);
	envir->env[array] = my_strdup(tmp);
	return (0);
}

int old_find_array(t_environ *envir)
{
	int number = 0;
	int nb = 0;

	while (envir->env[nb] != NULL) {
		if (envir->env[nb][0] == 'O' && envir->env[nb][1] == 'L' && envir->env[nb][2] == 'D'
		    && envir->env[nb][3] == 'P' && envir->env[nb][4] == 'W' && envir->env[nb][5] == 'D' ) {
			number = nb;
		}
		nb  = nb + 1;
	}
	return (number);
}

int my_chdir(char **command, t_environ *envir)
{
	char *home = home = home_find(envir);
	char *oldpwd = old_pwd(envir);

	if (command[0][0] == 'c' && command[0][1] == 'd' &&
	    command[0][2] == '\0') {
		my_set_old_pwd(envir);
		if (command[1] == NULL)
			chdir(home);
		else if (command[1][0] == '-')
			chdir(oldpwd);
		else
			chdir(command[1]);
		return (1);
	}
	free(home);
	free(oldpwd);
	return (0);
}

char *home_find(t_environ *envir)
{
	int number = 0;
	int nb = 0;
	char **path;

	while (envir->env[nb] != NULL) {
		if (envir->env[nb][0] == 'H' && envir->env[nb][1] == 'O' && envir->env[nb][2] == 'M'
		    && envir->env[nb][3] == 'E' && envir->env[nb][4] == '=' ) {
			number = nb;
		}
		nb  = nb + 1;
	}
	path = path_to_array(envir->env[number], 5);
	return (path[0]);
}

char *old_pwd(t_environ *envir)
{
	int number = 0;
	int nb = 0;
	char **path;

	while (envir->env[nb] != NULL) {
		if (envir->env[nb][0] == 'O' && envir->env[nb][1] == 'L' && envir->env[nb][2] == 'D'
		    && envir->env[nb][3] == 'P' && envir->env[nb][4] == 'W' && envir->env[nb][5] == 'D' ) {
			number = nb;
		}
		nb  = nb + 1;
	}
	path = path_to_array(envir->env[number], 7);
	return (path[0]);
}
