##
## Makefile for reference in /home/antoine.hartwig
## 
## Made by Antoine Hartwig
## Login   <antoine.hartwig@epitech.net>
## 
## Started on  Sat Oct 15 17:49:46 2016 Antoine Hartwig
## Last update Thu Feb  2 13:18:34 2017 Louis HATTE
##

SRC	= main.c \
	  help.c \
	  get_next_line.c \
	  check_coords.c \
	  errorMap.c \
	  errorMap2.c

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Iinclude/ #-W -Wall -Wextra -pedantic -g3

NAME	= navy

RM	= rm -rf

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lmy

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
