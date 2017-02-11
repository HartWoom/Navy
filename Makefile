##
## Makefile for reference in /home/antoine.hartwig
## 
## Made by Antoine Hartwig
## Login   <antoine.hartwig@epitech.net>
## 
## Started on  Sat Oct 15 17:49:46 2016 Antoine Hartwig
## Last update Sat Feb 11 10:22:01 2017 Antoine Hartwig
##

SRC	= main.c \
	  help.c \
	  start_game.c \
	  send_confirm.c \
	  encryption.c \
	  set_navy.c \
	  attack.c \
	  host_first_round.c \
	  updating_map.c \
	  my_strtowordtab2.c \
	  createMap.c \
	  errorMap.c \
	  errorMap2.c \
	  my_put.c \
	  ping.c \
	  my_simple_swap.c \
	  display_map.c

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Iinclude/ -W -Wall -Wextra -pedantic

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
