/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** path.c
*/

#include "my.h"

char **path_find(t_environ *envir)
{
	int number = 0;
	int nb = 0;
	char **path = NULL;

	while (envir->env[nb] != NULL) {
		if (envir->env[nb][0] == 'P' && envir->env[nb][1] == 'A' && envir->env[nb][2] == 'T'
		    && envir->env[nb][3] == 'H' && envir->env[nb][4] == '=' ) {
			number = nb;
		}
		nb = nb + 1;
	}
	path = path_to_array(envir->env[number], 5);
	return (path);
}

char **path_to_array(char *path, int nb)
{
	int arr = 0;
	int line = 0;
	int len = my_strlen(path);
	char **allpath = malloc(sizeof(char *) * len);

	allpath[arr] = malloc(sizeof(char) * len);
	while (path[nb] != '\0') {
		allpath[arr][line] = path[nb];
		line = line + 1;
		nb = nb + 1;
		if (path[nb] == ':') {
			allpath[arr][line] = '/';
			allpath[arr][line + 1] = '\0';
			arr = arr + 1;
			line = 0;
			nb = nb + 1;
			allpath[arr] = malloc(sizeof(char) * len);
		}
	}
	allpath[arr][line] = '/';
	allpath[arr][line + 1] = '\0';
	allpath[arr + 1] = NULL;
	return (allpath);
}
