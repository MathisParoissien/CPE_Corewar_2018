##
## EPITECH PROJECT, 2019
## lib
## File description:
## Makefile
##

SRCS	=	my_putchar.c \
			my_putstr.c \
			my_strlen.c \
			my_getnbr.c \
			my_put_nbr.c \
			my_str_to_wortab.c \
			my_strcat.c \
			my_strncat.c \
			my_strcmp.c \
			my_strncmp.c \
			my_strcpy.c \
			my_strncpy.c \
			my_strdup.c \
			my_strndup.c \
			get_next_line.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):
	gcc -c *.c
	ar rc $(NAME) *.o
	cp -r my.h ../../include

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
