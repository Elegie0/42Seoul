CC			= gcc

CFLAG		= -Wall -Wextra -Werror

SRC			= factorization.c	factorization_util.c	main.c

OBJ			= $(SRC:.c=.o)

NAME		= factorization

all : $(NAME)

$(NAME) : $(OBJ) factorization_header.h
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)

$(OBJ):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

cl:
	rm -rf ./*.o

fcl:
	rm -rf ./*.o $(NAME)

re: fcl $(NAME)