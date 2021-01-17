##
## EPITECH PROJECT, 2018
## My_runner
## File description:
## My_runner's makefile
##

SRCDIR  =       src

INCDIR =	include

SRC     =	$(SRCDIR)/malloc.c \
			$(SRCDIR)/additional.c \
			$(SRCDIR)/utils.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_malloc

CFLAGS  =       -W -I include/

all:            $(NAME)

$(NAME):
		gcc -c -fpic src/malloc.c src/additional.c src/utils.c
		gcc additional.o malloc.o utils.o -shared -o libmy_malloc.so

clean:
		rm -f $(OBJ)
		rm -f *.o
		rm -f *.so

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

