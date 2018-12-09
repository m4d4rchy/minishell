/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my_realloc_array.c
*/

#include "lib.h"

char **my_realloc_array(char **array, int size)
{
	char **new = NULL;
	int actual_size = my_argvlen(array);
	int i = 0;

	new = malloc(sizeof(char *) * (actual_size + size + 1));
	if (new == NULL)
		return (NULL);
	for (i = 0; array[i] != NULL; i += 1) {
		new[i] = NULL;
		new[i] = my_strdup(array[i]);
		if (new[i] == NULL)
			return (NULL);
	}
	while (i < (actual_size + size + 1)) {
		new[i] = NULL;
		i += 1;
	}
	my_free_array(array);
	return (new);
}
