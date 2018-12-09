##
## Makefile
## 
## Made by Benmessahel Yassine
## Login   <yassine.b@epitech.net>
## 
## Started on  Mon Mar 13 14:42:24 2017 Benmessahel Yassine
## Last update Sun Jan 21 23:38:51 2018 Yassine Benmessahel
##

CC	= 	gcc

LDFLAGS	= 	../libmy.a

LSRC	=	my_strlen.c		\
		my_printf.c		\
		my_printf_num.c		\
		my_print_params.c	\
		my_putchar.c		\
		my_put_long.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_strcmp.c		\
		my_realloc_array.c	\
		word_to_array.c		\
		my_free_array.c		\
		my_strdup.c		\
		my_argvlen.c

OBJS 	= 	$(LSRC.c=.o)


all: 		$(OBJS)
		$(CC) -c $(LSRC)
		ar rc ../libmy.a *.o

clean:
		rm  lib/my/*.o

fclean: 	clean
		$(RM) $(LDFLAGS)

re: 		fclean all

.PHONY: 	all clean fclean re
