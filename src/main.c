/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
	t_environ envir;
	char **allpath = NULL;
	(void)argv;
	(void)argc;
	(void)env;
	(void)envir;

	signal(SIGINT, SIG_IGN);
	my_init_env(&envir, env);
	allpath = path_find(&envir);
	my_set_old_pwd(&envir);
	main_shell(&envir, allpath);
	return (0);
}

int main_shell(t_environ *envir, char **allpath)
{
	char *input = NULL;
	size_t bufsize = 32;
	char **command = NULL;
	int check = 0;
	int child_process_status;
	(void)allpath;

	while (1) {
		my_print_prompt();
		check = getline(&input, &bufsize, stdin);
		command = my_word_to_array(input);
		my_exit_ctrld(command, envir, check);
		if (my_parser(command, envir) != 1 &&
		    my_envparser(command, envir) != 1) {
			if (fork() == 0) {
				my_main_excve(command, allpath, envir);
			}
		}
		wait(&child_process_status);
	}
	free_array(command);
	free_array(allpath);
	free(input);
	return (0);
}

void my_print_prompt(void)
{
	char cwd[1000];
	int size = 0;

	getcwd(cwd, 1000);
	size = my_strlen(cwd);
	write(0, cwd, size);
	write(0, "> ", 2);
}
