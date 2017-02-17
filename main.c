/*
** main.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 08:30:05 2017 Louis HATTE
** Last update Fri Feb 17 13:03:50 2017 Louis HATTE
*/

#include "include/my.h"

char    *my_swap(char *str, int a, int b)
{
  char tmp;

  tmp = str[a];
  str[a] = str[b];
  str[b] = tmp;
  return (str);
}

int	errorInput(int ac, char **av)
{
  int	fd;

  if (ac != 2 && ac != 3)
    return (1);
  if (ac == 2)
    {
      if (!(my_strcomp(av[1], "-h", 0, my_strlen(av[1]))) &&
	  (fd = open(av[1], O_RDONLY)) == -1)
	{
	  close(fd);
	  return (1);
	}
    }
  else
    if ((fd = open(av[2], O_RDONLY)) == -1)
      {
	close(fd);
	return (1);
      }
  return (0);
}

int		main(int ac, char **av)
{
  t_navy	*navy;
  t_error	error;

  if ((navy = malloc(sizeof(t_navy))) == NULL)
    return (84);
  if (errorInput(ac, av))
    return (84);
  if (my_strcomp(av[1], "-h", 0, my_strlen(av[1])))
    {
      hDisplay();
      return (0);
    }
  if (errorMap(ac, av, &error))
    return (84);
  return (start_game(ac, av, navy, &error));
}
