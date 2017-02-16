/*
** display_map.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 13:59:22 2017 Louis HATTE
** Last update Thu Feb 16 13:59:24 2017 Louis HATTE
*/

#include "include/my.h"

void	display_map(t_navy *navy, int map)
{
  int       j;

  j = 0;
  if (map == 1)
    while (j < 23)
      my_putstr(navy->map1[j++]);
  else if (map == 2)
    while (j < 23)
      my_putstr(navy->map2[j++]);
}
