/*
** my_getnbr.c for  in /home/louis.hatte/PSU_2016_minishell1/lib/my
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Sat Jan 21 00:10:37 2017 Louis HATTE
** Last update Sun Jan 22 17:31:48 2017 Louis HATTE
*/

#include "my.h"

int     my_getnbr(char *str)
{
  int   op;
  int   result;

  op = 1;
  result = 0;
  if (*str == '-')
    {
      op = -1;
      str++;
    }
  while (*str != '\0')
    {
      result = result * 10 + *str - 48;
      str++;
    }
  if (op == -1)
    result = result * op;
  return (result);
}
