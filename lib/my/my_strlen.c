/*
** my_strlen.c for  in /home/louis.hatte/TEST
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Wed Jan 18 12:37:10 2017 Louis HATTE
** Last update Sun Jan 22 17:32:38 2017 Louis HATTE
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++ + 1] != '\0');
  return (i);
}
