##
## Makefile for reference in /home/antoine.hartwig
## 
## Made by Antoine Hartwig
## Login   <antoine.hartwig@epitech.net>
## 
## Started on  Sat Oct 15 17:49:46 2016 Antoine Hartwig
## Last update Fri Feb  3 10:24:17 2017 Louis HATTE
##

SRC	= main.c \
	  help.c \
	  errorMap.c \
	  errorMap2.c \
	  my_strtowordtab2.c \
	  createMap.c

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Iinclude/ -W -Wall -Wextra -pedantic -g3

NAME	= navy

RM	= rm -rf

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lmy -lgnl

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
