/*
** my_strtowordtab2.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb  2 17:28:38 2017 Louis HATTE
** Last update Fri Feb  3 10:11:57 2017 Louis HATTE
*/

#include "include/my.h"

int     my_lines2(char *str, char c)
{
  int   i;
  int   count;

  i = (count = 0);
  while (str[i] != '\0')
    if (str[i++] == c)
      count++;
  count++;
  return (count);
}

int     *my_columns2(char *str, char c, int lines)
{
  int   *columns;
  int   i;
  int   j;
  int   count;

  if (!(columns = malloc(sizeof(int) * lines)))
    return (NULL);
  i = (j = (count = 0));
  while (str[i] != '\0')
    {
      if (str[i++] == c)
	{
	  columns[j++] = count;
	  count = 0;
	}
      else
	count++;
    }
  columns[j] = count;
  return (columns);
}

char    **my_strToWordTab2(char *str, char c)
{
  int   lines;
  int   *columns;
  char  **tab;
  int   i;
  int   j;
  int   k;

  lines = my_lines2(str, c);
  columns = my_columns2(str, c, lines);
  if (!(tab = malloc(sizeof(char *) * (lines + 1))))
    return (NULL);
  i = (j = (k = 0));
  while (j < lines)
    {
      if (!(tab[j] = malloc(sizeof(char) * (columns[j] + 2))))
	return (NULL);
      while (str[i] != c && str[i] != '\0')
	tab[j][k++] = str[i++];
      tab[j][k++] = '\n';
      tab[j++][k] = '\0';
      k = 0;
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
