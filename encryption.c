/*
** encryption.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Sat Feb  4 14:41:46 2017 Louis HATTE
** Last update Sat Feb  4 14:41:47 2017 Louis HATTE
*/

#include "include/my.h"

int	authorize_entry(char *cds)
{
  if (((cds[0] >= 'A' && cds[0] <= 'H') || (cds[0] >= 'a' && cds[0] <= 'h'))
      && ((cds[1] >= 'A' && cds[1] <= 'H') || (cds[1] >= 'a' && cds[1] <= 'h')))
    return (1);
  if ((cds[0] >= '1' && cds[0] <= '8') && (cds[1] >= '1' && cds[1] <= '8'))
    return (1);
  return (0);
}

int	send_first_signal(char *pid, char coords, char *key)
{
  int	i;

  i = 0;
  while (key[i] != coords)
    i++;
  while (i != 0)
    {
      if (kill(my_getnbr(pid), SIGUSR1) == -1)
	return (-1);
      usleep(10000);
      i--;
    }
  if (kill(my_getnbr(pid), SIGUSR2) == -1)
    return (-1);
  usleep(10000);
  return (0);
}

int	send_second_signal(char *pid, char coords, char *key)
{
  int	i;

  i = 0;
  while (key[i] != coords)
    i++;
  while (i != 0)
    {
      if (kill(my_getnbr(pid), SIGUSR1) == -1)
        return (-1);
      usleep(10000);
      i--;
    }
  if (kill(my_getnbr(pid), SIGUSR2) == -1)
    return (-1);
  usleep(10000);
  return (0);
}

void	encryption(char *pid, char *coords)
{
  char	*key;

  if (my_strlen(coords) != 2 || authorize_entry(coords) == 1)
    return;
  if ((key = malloc(sizeof(char) * 17)) == NULL)
    return;
  key = "ABCDEFGH12345678";
  if (send_first_signal(pid, coords[0], key) == -1)
    return;
  if (send_second_signal(pid, coords[1], key) == -1)
    return;
}
