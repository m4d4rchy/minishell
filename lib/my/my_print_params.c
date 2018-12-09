/*
** EPITECH PROJECT, 2017
** my_print_params
** File description:
**
*/

void my_putchar(char c);
int my_putstr(char const *str);

void	my_print_params(int argc, char **argv)
{
	int	count;

	count = 0;
	while (count != argc) {
		my_putstr(argv[count]);
		my_putstr("\n");
		count = count + 1;
	}
}
