/*
** check_coords.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb  2 13:15:45 2017 Louis HATTE
** Last update Thu Feb  2 13:22:58 2017 Louis HATTE
*/

#include "include/my.h"

int             check_coords_part2(t_coords *var)
{
  if ((var->char1 - var->char3) == 0 && (var->char2 - var->char4) != 0)
    {
      if (((var->char2 - var->char4 + 1) != var->size)
          && ((var->char4 - var->char2 + 1) != var->size))
        return (-1);
    }
  else if ((var->char1 - var->char3) != 0 && (var->char2 - var->char4) == 0)
    {
      if (((var->char1 - var->char3 + 1) != var->size)
          && ((var->char3 - var->char1 + 1) != var->size))
        return (-1);
    }
  else
    return (-1);
  return (0);
}

int             check_coords(int fd)
{
  int           i;
  int           k;
  t_coords      *var;
  char		*buffer;

  if ((buffer = malloc(sizeof(char) * 33)) == NULL)
    return (1);
  read(fd, buffer, 1024);
  if ((var = malloc(sizeof(t_coords))) == NULL)
    return (1);
  i = 2;
  k = 0;
  while (++k != 5)
    {
      var->size = buffer[i - 2] - 48;
      var->char1 = buffer[i];
      var->char2 = buffer[i + 1];
      var->char3 = buffer[i + 3];
      var->char4 = buffer[i + 4];
      if (check_coords_part2(var) == -1)
        return (1);
      i += 8;
    }
  return (0);
}
