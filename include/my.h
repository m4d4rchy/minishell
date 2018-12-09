/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** my.h
*/

#include "../lib/my/lib.h"
#include "struct.h"
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#ifndef MY_H
#define MY_H

/*  main.c  */
void my_print_prompt(void);
int main_shell(t_environ *, char **);

/* init.c */
int my_init_env(t_environ *, char **);

/*  chdir.c  */
int my_chdir(char **, t_environ *);
char *home_find(t_environ *);
char *old_pwd(t_environ *);
int my_set_old_pwd(t_environ *);
int old_find_array(t_environ *);

/*  commande.c  */
int my_main_excve(char **, char **, t_environ *);
int my_excve(char **, t_environ *);
int my_parser(char **, t_environ *);
char **my_command_check(char **, char *);
char **my_word_to_array(char *);

/*  exit.c  */
int my_exit(char **, t_environ *);
int my_exit_ctrld(char **, t_environ *, int);
void free_array(char **);

/*  env.c */
int my_envparser(char **, t_environ *);
int my_env(char **, t_environ *);
int my_setenv(char **, t_environ *);
int my_unsetenv(char **, t_environ *);

/* clear.c */
int my_clear(char **, t_environ *);

/*  path.c  */
char **path_find(t_environ *envir);
char **path_to_array(char *, int);

#endif
