##
## Makefile for reference in /home/antoine.hartwig
## 
## Made by Antoine Hartwig
## Login   <antoine.hartwig@epitech.net>
## 
## Started on  Sat Oct 15 17:49:46 2016 Antoine Hartwig
## Last update Mon Jan 30 17:32:46 2017 Antoine Hartwig
##

SRC	=	main.c		\
		display_h.c

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/ -W -Wall -Wextra -pedantic -g3

NAME	=	navy

RM	=	rm -rf

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lmy

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
