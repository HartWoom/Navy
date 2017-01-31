/*
** my_strcopy.c for  in /home/louis.hatte/TEST
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Wed Jan 18 12:25:12 2017 Louis HATTE
** Last update Sun Jan 22 17:36:31 2017 Louis HATTE
*/

#include "my.h"

char	*my_strcopy(char *str, int n, int m)
{
  char	*copy;
  int	i;

  i = 0;
  if (!(copy = malloc(sizeof(char) * m - n + 1)))
    return (NULL);
  while (n < m)
    copy[i++] = str[n++];
  copy[n] = '\0';
  return (copy);
}
