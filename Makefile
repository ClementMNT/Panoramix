## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile

# Compiler
CC      := gcc
CFLAGS  := -g

# Project
NAME    := panoramix
SRC     := $(wildcard *.c)
OBJ     := $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
