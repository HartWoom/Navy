/*
** my_strconcatenate.c for  in /home/louis.hatte/TEST
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Wed Jan 18 12:49:29 2017 Louis HATTE
** Last update Sun Jan 22 17:33:39 2017 Louis HATTE
*/

#include "my.h"

char	*my_strcat(char *a, char *b)
{
  int	i;
  int	j;
  char	*ab;

  i = my_strlen(a) + my_strlen(b);
  if (!(ab = malloc(sizeof(char) * i + 1)))
    return (NULL);
  i = (j = 0);
  while (a[i] != '\0')
    ab[i] = a[i++];
  while (b[j] != '\0')
    ab[i++] = b[j++];
  ab[i] = '\0';
  return (ab);
}
