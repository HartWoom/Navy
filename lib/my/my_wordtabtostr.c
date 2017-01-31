/*
** my_wordtabtostr.c for  in /home/louis.hatte/TEST
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Sat Jan 21 22:58:55 2017 Louis HATTE
** Last update Sun Jan 22 17:34:04 2017 Louis HATTE
*/

#include "my.h"

char	*my_wordTabToStr(char **tab, char c)
{
  int	i;
  int	j;
  int	count;
  char	*str;

  i = ( j = (count = 0));
  while (tab[i] != NULL && (j = 0))
    {
      while (tab[i][j++] != '\0')
	count++;
      i++;
    }
  if (!(str = malloc(sizeof(char) * count + i + 1)))
    return (NULL);
  i = ( j = (count = 0));
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	str[count++] = tab[i][j++];
      str[count++] = c;
      i++;
      j = 0;
    }
  str[count] = '\0';
  return (str);
}
