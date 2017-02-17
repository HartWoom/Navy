/*
** errorMap3.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Fri Feb 17 11:26:49 2017 Louis HATTE
** Last update Fri Feb 17 11:27:26 2017 Louis HATTE
*/

#include "include/my.h"

int     checkBoat3(t_error *error)
{
  int   j;

  j = 0;
  while (j < 4)
    {
      if (error->file[j][2] != error->file[j][5] &&
	  error->file[j][3] != error->file[j][6])
	return (1);
      j++;
    }
  return (0);
}

int     checkBoat2(t_error *error)
{
  int   a;
  int   j;

  j = 0;
  while (j < 4)
    {
      a = my_getnbr2(error->file[j]);
      if (error->file[j][3] == error->file[j][6])
	{
	  if (error->file[j][2] >= error->file[j][5])
	    {
	      if (error->file[j][2] - error->file[j][5] + 1 != a)
		return (1);
	    }
	  else
	    {
	      if (error->file[j][5] - error->file[j][2] + 1 != a)
		return (1);
	    }
	}
      j++;
    }
  return (0);
}


int     checkBoat(t_error *error)
{
  int   a;
  int   j;

  j = 0;
  while (j < 4)
    {
      a = my_getnbr2(error->file[j]);
      if (error->file[j][2] == error->file[j][5])
	{
	  if (error->file[j][3] >= error->file[j][6])
	    {
	      if (error->file[j][3] - error->file[j][6] + 1 != a)
		return (1);
	    }
	  else
	    {
	      if (error->file[j][6] - error->file[j][3] + 1 != a)
		return (1);
	    }
	}
      j++;
    }
  return (0);
}

int     cleanFile(t_error *error)
{
  int   j;
  char  tmp;

  j = 0;
  while (j < 4)
    {
      if (error->file[j][2] >= '1' && error->file[j][2] <= '8')
	{
	  tmp = error->file[j][2];
	  error->file[j][2] = error->file[j][3];
	  error->file[j][3] = tmp;
	}
      if (error->file[j][5] >= '1' && error->file[j][5] <= '8')
	{
	  tmp = error->file[j][5];
	  error->file[j][5] = error->file[j][6];
	  error->file[j][6] = tmp;
	}
      j++;
    }
  return (0);
}
