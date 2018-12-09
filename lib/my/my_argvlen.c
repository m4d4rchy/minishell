/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my_argvlen.c
*/

#include "lib.h"

int my_argvlen(char **argv)
{
	int i = 0;

	while (argv[i] != NULL && argv[i][0] != '\0') {
		i = i + 1;
	}
	return (i);
}
