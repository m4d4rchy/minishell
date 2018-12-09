/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my_strdup.c
*/

#include "lib.h"

char *my_strdup(char const *src)
{
	int count = 0;
	int lenght = my_strlen(src);
	char *dest = malloc(sizeof(char) * (lenght + 1));

	if (dest == NULL)
		return (NULL);
	while (src[count] != '\0') {
		dest[count] = src[count];
		count = count + 1;
	}
	dest[count] = '\0';
	return (dest);
}
