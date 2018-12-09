/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my_free_array.c
*/

#include "lib.h"

void my_free_array(char **array)
{
	int i = 0;
	
	while (array[i] != NULL) {
		free(array[i]);
		i = i + 1;
	}
}
