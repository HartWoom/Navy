/*
** errorMap2.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Fri Feb 17 11:25:25 2017 Louis HATTE
** Last update Fri Feb 17 11:26:24 2017 Louis HATTE
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
  while (*str && *str != ':')
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

int     errorLength(t_error *error)
{
  int   *length;
  int   i;
  int   j;
  int   a;

  if ((length = lengthTabler()) == NULL)
    return (1);
  i = (j = (a = 0));
  while (j < 4)
    {
      a = my_getnbr2(error->file[j]);
      while (a != length[i] && ++i < 4);
      if (a == length[i])
	length[i] = 1;
      i = 0;
      j++;
    }
  while (length[i++] == 1);
  if (i != 5)
    return (1);
  return (0);
}

int     checkFile2(t_error *error)
{
  int   j;

  j = 0;
  while (j < 4)
    {
      if (error->file[j][5] >= '1' && error->file[j][5] <= '8')
	{
	  if ((error->file[j][6] < 'A' || error->file[j][6] > 'H'))
	    return (1);
	}
      else if (error->file[j][5] >= 'A' && error->file[j][5] <= 'H')
	{
	  if ((error->file[j][6] < '1' || error->file[j][6] > '8'))
	    return (1);
	}
      else
	return (1);
      j++;
    }
  return (0);
}

int     checkFile(t_error *error)
{
  int   j;

  j = 0;
  while (j < 4)
    {
      if ((error->file[j][1] != ':') || (error->file[j][4] =! ':') ||
	  (error->file[j][0] < '2' || error->file[j][0] > '5') ||
	  (error->file[j][7] != '\n'))
	return (1);
      if (error->file[j][2] >= '1' && error->file[j][2] <= '8')
	{
	  if (error->file[j][3] < 'A' || error->file[j][3] > 'H')
	    return (1);
	}
      else if (error->file[j][2] >= 'A' && error->file[j][2] <= 'H')
	{
	  if (error->file[j][3] < '1' || error->file[j][3] > '8')
	    return (1);
	}
      else
	return (1);
      j++;
    }
  return (0);
}
