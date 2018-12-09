/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** error.c
*/

#include "my.h"

int check_env(char **env)
{
	if (env[0] == NULL)
		return (1);
	return (0);
}
