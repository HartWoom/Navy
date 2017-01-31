/*
** main.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 08:30:05 2017 Louis HATTE
** Last update Tue Jan 31 08:46:33 2017 Louis HATTE
*/

#include "include/my.h"

int	error_management(int ac, char **av)
{
  if (ac != 2 && ac != 3)
    return (1);
  if (my_str_cmp(av[1], "-h") == 0)
    {
      display_h();
      return (0);
    }
  if (ac == 2)
    gather_map(av[1]);
  /* else */
  /*   gather_map(av[2]); */
  return (0);
}

int	main(int ac, char **av)
{
  if (error_management(ac, av) || errorMap(av))
    return (84);
  return (0);
}
