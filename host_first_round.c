/*
** host_first_round.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 13:59:54 2017 Louis HATTE
** Last update Fri Feb 17 13:37:06 2017 Antoine Hartwig
*/

#include "include/my.h"

int	my_glob;

int	host_first_round_part2(t_navy *navy)
{
  static int	usr1 = 0;

  pause();
  if (my_glob == 1)
    usr1++;
  if (my_glob == 2 && usr1 == 1)
    {
      my_puts(my_strcapitalize(navy->sent), ": hit\n");
      navy->ships++;
      return (1);
    }
  if (my_glob == 2 && usr1 == 2)
    {
      my_puts(my_strcapitalize(navy->sent), ": missed\n");
      return (1);
    }
  return (0);
}

void	host_first_round(int ac, t_navy *navy, t_error *error)
{
  int	flag;

  navy->other_pid = my_glob;
  flag = 0;
  my_putstr("enemy connected\n\n");
  createMap(ac, navy, error);
  my_putstr("\nattack:  ");
  usleep(15000);
  kill(navy->other_pid, SIGUSR1);
  usleep(8000);
  while ((navy->sent = get_next_line(0)))
    {
      if (encryption(navy, navy->other_pid, navy->sent) == 1)
	{
	  my_putstr("wrong position");
	  attack(navy->other_pid, navy);
	  flag = 1;
	}
      break;
    }
  if (flag == 0)
    while (1)
      if (host_first_round_part2(navy) == 1)
	break;
}
