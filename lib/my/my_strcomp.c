/*
** my_strcompare.c for  in /home/louis.hatte/TEST
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Wed Jan 18 11:39:13 2017 Louis HATTE
** Last update Sun Jan 22 17:32:56 2017 Louis HATTE
*/

#include "my.h"

int	my_strcomp(char *a, char *b, int n, int m)
{
  while (a[n] == b[n] && n < m && a[n] != '\0' && b[n] != '\0')
    n++;
  if (n == m)
    return (1);
  else
    return (0);
}
