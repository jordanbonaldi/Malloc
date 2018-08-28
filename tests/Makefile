##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

NAME = tests

CFLAGS += -W -Wextra -Wall -Werror
CFLAGS += -I../include/ --coverage

SRCS	=	basic.c \
		bigmallocs.c \
		double_free.c \
		thread.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -pthread -lcriterion --coverage -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.gcov

re: fclean all

.PHONY: all clean fclean re
