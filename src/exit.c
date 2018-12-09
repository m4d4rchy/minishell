/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** exit.c
*/

#include "my.h"

int my_exit(char **input, t_environ *envir)
{
	int nb = 0;
	(void)envir;

	if (input[1] == NULL) {
		exit(0);
	}
	else if (input[1] != NULL) {
		nb = my_getnbr(input[1]);
		exit(nb);
	}
	return (0);
}

int my_exit_ctrld(char **command, t_environ *envir, int check)
{
	if (check == -1) {
		my_putstr("\n");
		my_exit(command, envir);
	}
	return (0);
}

void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL) {
		free(array[i]);
		i = i + 1;
	}
}
