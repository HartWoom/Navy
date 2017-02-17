/*
** real_start.c for  in /home/louis.hatte/PSU_2016_navy
**
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
**
** Started on  Thu Feb 16 16:58:20 2017 Louis HATTE
** Last update Fri Feb 17 13:16:02 2017 Louis HATTE
*/

#include "include/my.h"

int	start_game_part2(int ac, char **av, t_navy *navy, t_error *error)
{
  int	_return;

  if ((_return = client(ac, av, navy, error)) == 20)
    {
      my_putstr("\nI won\n");
      return (0);
    }
  if (_return == 10)
    my_putstr("\nEnemy won\n");
  if (_return == 84)
    return (84);
  return (1);
}

int     start_game(int ac, char **av, t_navy *navy, t_error *error)
{
  int	_return;

  if (ac == 2)
    {
      if ((_return = host(ac, navy, error)) == 20)
        {
          my_putstr("\nI won\n");
          return (0);
        }
      if (_return == 10)
	my_putstr("\nEnemy won\n");
      if (_return == 84)
	return (84);
      return (1);
    }
  else if (ac == 3)
    return (start_game_part2(ac, av, navy, error));
  return (0);
}
