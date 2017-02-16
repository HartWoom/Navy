/*
** attack.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 13:59:11 2017 Louis HATTE
** Last update Thu Feb 16 15:15:14 2017 Antoine Hartwig
*/

#include "include/my.h"

int	my_glob;

void	tell_if_hit_or_not_from1(t_navy *navy)
{
  if (navy->map2[COORDS1][COORDS0] >= '2'
      && navy->map2[COORDS1][COORDS0] <= '5')
    {
      my_puts(navy->coords, ":  hit");
      navy->ships_sunk++;
      simple_ping(navy->other_pid);
    }
  else if (navy->map2[COORDS1][COORDS0] == '.'
	   || navy->map2[COORDS1][COORDS0] == 'o'
	   || navy->map2[COORDS1][COORDS0] == 'x')
    {
      my_puts(navy->coords, ": missed");
      double_ping(navy->other_pid);
    }
}

void	tell_if_hit_or_not_from2(t_navy *navy)
{
  if (navy->map1[COORDS1][COORDS0] >= '2'
      && navy->map1[COORDS1][COORDS0] <= '5')
    {
      my_puts(navy->coords, ":  hit");
      navy->ships_sunk++;
      simple_ping(navy->other_pid);
    }
  else if (navy->map1[COORDS1][COORDS0] == '.'
	   || navy->map1[COORDS1][COORDS0] == 'o'
	   || navy->map1[COORDS1][COORDS0] == 'x')
    {
      my_puts(navy->coords, ": missed");
      double_ping(navy->other_pid);
    }
  my_putchar('\n');
}

void	tell_if_hit_or_not(t_navy *navy, int from)
{
  usleep(4000);
  if (navy->coords[0] >= '1' && navy->coords[0] <= '8')
    my_simple_swap(navy->coords);
  if (from == 1)
    tell_if_hit_or_not_from1(navy);
  if (from == 2)
    tell_if_hit_or_not_from2(navy);
}

int	attack_condition(t_navy *navy, int usr1)
{
  if (my_glob == 2 && usr1 == 1)
    {
      my_puts(navy->sent, ": hit");
      navy->ships++;
      return (1);
    }
  if (my_glob == 2 && usr1 == 2)
    {
      my_puts(navy->sent, ": missed");
      return (1);
    }
  return (0);
}

void	attack(int pid, t_navy *navy)
{
  char	*coords;
  int	usr1;

  usr1 = 0;
  my_putstr("\nattack: ");
  while ((coords = get_next_line(0)))
    {
      if (encryption(navy, pid, coords) == 1)
	{
	  my_putstr("wrong position");
	  my_putstr("\nattack: ");
	}
      else
	break;
    }
  navy->sent = my_strcapitalize(coords);
  while (1)
    {
      pause();
      if (my_glob == 1)
  	usr1++;
      if (attack_condition(navy, usr1) == 1)
  	break;
    }
  my_putchar('\n');
}
