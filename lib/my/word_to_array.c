/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** word_to_array.c
*/

#include "lib.h"

char **my_word_to_array(char *input)
{
	char **word_to_array = NULL;
	if (input == NULL)
		return (NULL);
	input = my_clear_space(input);
	word_to_array = put_to_array(input);
	free(input);
	return (word_to_array);
}

char **put_to_array(char *input)
{
	int i = 0;
	int a = 0;
	int b = 0;
	char **tmp = malloc(sizeof(char *) * 50);

	tmp[a] = malloc(sizeof(char) * my_strlen(input));
	while (input[i] != '\0') {
		tmp[a][b] = input[i]; 
		i = i + 1;
		b = b + 1;
		if (input[i] == ' ' || input[i] == '\0') {
			tmp[a][b] = '\0';
			a = a + 1;
			tmp[a] = malloc(sizeof(char) * my_strlen(input));
			i = i + 1;
			b = 0;
		}
	}
	tmp[a] = NULL;
	return (tmp);
}

char **my_create_array(char **array, int alloc, int a, int b, int size)
{
	array[a][b] = '\0';
	array = my_realloc_array(array, alloc);
	array[a] = malloc(sizeof(char) * size);
	return (array);
}

char *my_clear_space(char *input)
{
	int i = 0;
	int j = 0;
	int separator = 0;
	char *cpy = malloc(sizeof(char) * my_strlen(input));
	
	while (input[i] != '\0') {
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n') {
			if (separator == 1 && j != 0) {
				cpy[j] = ' ';
				j = j + 1;
			}
			cpy[j] = input[i];
			j = j + 1;
			separator = 0;
		}
		else if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
			separator = 1;
		i = i + 1;
	}
	return (cpy);
}
