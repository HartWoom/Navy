/*
** main.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 08:30:05 2017 Louis HATTE
** Last update Fri Feb  3 15:01:48 2017 Antoine Hartwig
*/

#include "include/my.h"

int	errorInput(int ac, char **av)
{
  if (ac != 2 && ac != 3)
    return (1);
  if (ac == 2)
    {
      if (!(my_strcomp(av[1], "-h", 0, my_strlen(av[1]))) &&
	  open(av[1], O_RDONLY) == -1)
	return (1);
    }
  else
    {
      if (open(av[2], O_RDONLY) == -1)
	return (1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (errorInput(ac, av))
    return (84);
  if (my_strcomp(av[1], "-h", 0, my_strlen(av[1])))
    {
      hDisplay();
      return (0);
    }
  if (errorMap(ac, av))
    return (84);
  createMap(ac, av);
  if (start_game(ac, av) == -1)
    return (84);
  return (0);
}
