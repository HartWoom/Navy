/*
** errorMap2.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 12:56:57 2017 Louis HATTE
** Last update Tue Jan 31 13:07:14 2017 Louis HATTE
*/

#include "include/my.h"

int     my_getnbr2(char *str)
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
  while (*str != ':')
    {
      result = result * 10 + *str - 48;
      str++;
    }
  if (op == -1)
    result = result * op;
  return (result);
}

int     *lengthTabler()
{
  int   *length;

  if (!(length = malloc(sizeof(int) * 4)))
    return (NULL);
  length[0] = 2;
  length[1] = 3;
  length[2] = 4;
  length[3] = 5;
  return (length);
}
