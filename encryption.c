/*
** encryption.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 13:59:30 2017 Louis HATTE
** Last update Thu Feb 16 13:59:31 2017 Louis HATTE
*/

#include "include/my.h"

int	authorize_entry(char *cds)
{
  int	i;

  i = 0;
  if (((cds[0] >= 'A' && cds[0] <= 'H') || (cds[0] >= 'a' && cds[0] <= 'h'))
      && ((cds[1] >= 'A' && cds[1] <= 'H') || (cds[1] >= 'a' && cds[1] <= 'h')))
    return (1);
  if ((cds[0] >= '1' && cds[0] <= '8') && (cds[1] >= '1' && cds[1] <= '8'))
    return (1);
  while (i < 2)
    {
      if ((cds[i] < '1') || (cds[i] > '8' && cds[i] < 'A')
	  || (cds[i] > 'H' && cds[i] < 'a') || (cds[i] > 'h'))
	return (1);
      i++;
    }
  return (0);
}

int	send_signal(int pid, char coords, char *key)
{
  int	i;

  i = 0;
  if (coords >= 'a' && coords <= 'h')
    coords -= 32;
  while (key[i] != coords)
    i++;
  usleep(5000);
  while (i != 0)
    {
      if (kill(pid, SIGUSR1) == -1)
	return (-1);
      usleep(10000);
      i--;
    }
  if (kill(pid, SIGUSR2) == -1)
    return (-1);
  usleep(5000);
  return (0);
}

int	encryption(t_navy *navy, int pid, char *coords)
{
  if (my_strlen(coords) != 2 || authorize_entry(coords) == 1)
    return (1);
  if ((coords[0] >= 'A' && coords[0] <= 'H')
      || (coords[0] >= 'a' && coords[0] <= 'h'))
    {
      if (send_signal(pid, coords[0], navy->key) == -1)
	return (1);
      if (send_signal(pid, coords[1], navy->key) == -1)
	return (1);
    }
  else if (coords[0] >= '1' && coords[0] <= '8')
    {
      if (send_signal(pid, coords[1], navy->key) == -1)
	return (1);
      if (send_signal(pid, coords[0], navy->key) == -1)
	return (1);
    }
  return (0);
}
