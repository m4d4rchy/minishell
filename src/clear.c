/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** clear.c
*/

#include "my.h"

int my_clear(char **command, t_environ *envir)
{
	(void)command;
	(void)envir;
	const char *clear_screen_code = "\e[1;1H\e[2J";

	write(STDOUT_FILENO, clear_screen_code, 11);
	return (1);
}
