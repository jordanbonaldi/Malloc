##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

NAME = libmy_malloc.so

CFLAGS += -W -Wextra -Wall -Werror
CFLAGS += -Iinclude/ -g3 -fpic

SRCS =  src/malloc.c \
	src/realloc.c \
	src/calloc.c \
	src/free.c \
	src/show_alloc_mem.c \
	src/reallocf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS)

clean:
	make -C tests/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C tests/ fclean
	$(RM) $(NAME)

re: fclean all

tests_clean:
	make -C tests/ fclean

tests_run: re
	make -C tests/ all
	tests/tests

.PHONY: all clean fclean re
