/*
** my_putstr.c for  in /home/louis.hatte/CPool_Day04
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Oct  6 10:46:57 2016 Louis HATTE
** Last update Sun Jan 22 17:32:25 2017 Louis HATTE
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
