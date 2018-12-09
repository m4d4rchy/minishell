##
## EPITECH PROJECT, 2017
## Makefiles
## File description:
## 
##


CC	= 	gcc

LDFLAGS	= 	-Iinclude/ lib/libmy.a

FLAGS	=	-W -Wall -Wextra -Werror

NAME	= 	mysh

SRC 	=	src/main.c	\
		src/command.c	\
		src/path.c	\
		src/chdir.c	\
		src/env.c	\
		src/clear.c	\
		src/init.c	\
		src/error.c	\
		src/exit.c

OBJS 	= 	$(SRCS:.c=.o)


all: 		$(NAME)

$(NAME):	$(OBJS)
		make -C lib/my/
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)
		make -f lib/my/Makefile clean

fclean: 	clean
		$(RM) $(NAME)
re: 		fclean all

.PHONY: 	all clean fclean re
