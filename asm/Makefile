##
## EPITECH PROJECT, 2019
## PSU_tetris_2018
## File description:
## Makefile
##

NAME	= asm

CC	= gcc -g3

RM	= rm -f

SRCS	= ./src/main.c \
		  ./src/op.c \
		  ./src/init.c \
		  ./src/xmalloc.c \
		  ./src/get_body.c \
		  ./src/check_file.c \
		  ./src/champ.c \
		  ./src/name.c \
		  ./src/comment.c \
		  ./src/labels.c \
		  ./src/wima.c \
		  ./src/str_to_word_array_cor.c \
		  ./src/check_label.c \
		  ./src/opcode.c \
		  ./src/write.c \
		  ./src/write_op.c \
		  ./src/write_ld.c \
		  ./src/write_st.c \
		  ./src/write_add.c \
		  ./src/write_and.c \
		  ./src/write_or.c \
		  ./src/write_zjmp.c \
		  ./src/write_ldi.c \
		  ./src/write_sti.c \
		  ./src/write_lld.c \
		  ./src/my_strstr.c \
		  ./src/check_label_2.c \
		  ./src/labels_2.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

ECHO		+= echo -e

all: $(NAME) clean

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L ./lib/my -lmy
	rm -rf .vscode
	rm -rf ./include/libmy_printf.a
	rm -rf ./lib/my/libmy.a
	@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled\033[01;34m<-\033[01;34m---------------\033[01;00m'

clean:
	$(RM) $(OBJS)
	@$(ECHO) '\033[01;31m-----------------\033[01;31m->\033[01;33mAll clean\033[01;31m<-\033[01;31m----------------\033[01;00m'

fclean: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[01;36m---------------\033[01;36m->\033[01;36mBinary clean\033[01;36m<-\033[01;36m---------------\033[01;00m'

re: fclean all

.PHONY: all clean fclean re