/*
** errorMap.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:23:37 2017 Louis HATTE
** Last update Fri Feb 17 13:10:58 2017 Louis HATTE
*/

#include "include/my.h"

int	capitalizeFile(t_error *error)
{
  int	i;
  int	j;

  i = (j = 0);
  while (j < 4)
    {
      while (error->file[j][i] != '\0')
	{
	  if (error->file[j][i] >= 'a' && error->file[j][i] <= 'z')
	    error->file[j][i] = error->file[j][i] - 32;
	  i++;
	}
      i = 0;
      j++;
    }
  return (0);
}

int	takeFile(int ac, char **av, t_error *error)
{
  char	*str;
  int	fd;
  int	i;
  int	j;

  i = 0;
  j = 0;
  fd = chooseAv(ac, av);
  while ((str = get_next_line(fd)))
    {
      while (str[i] != '\0')
	{
	  error->file[j][i] = str[i];
	  i++;
	}
      error->file[j][i] = '\n';
      i = 0;
      j++;
    }
  return (0);
}

int	errorLines(int ac, char **av)
{
  char	buff[1];
  int	lines;
  int	fd;
  int	count;

  lines = 0;
  count = 0;
  fd = chooseAv(ac, av);
  while (read(fd, buff, 1) != 0)
    {
      if (buff[0] == '\n')
  	lines++;
      count++;
    }
  close(fd);
  if ((lines == 3 && count == 31) ||
      (lines == 4 && count == 32 && buff[0] == '\n'))
    return (0);
  return (1);
}

int	chooseAv(int ac, char **av)
{
  int	fd;

  if (ac == 2)
    fd = open(av[1], O_RDONLY);
  else
    fd = open(av[2], O_RDONLY);
  return (fd);
}

int		errorMap(int ac, char **av, t_error *error)
{
  int		i;

  i = 0;
  if (!(error->file = malloc(sizeof(char *) * 5)))
    return (1);
  error->file[4] = NULL;
  while (i < 4)
    {
      if (!(error->file[i] = malloc(sizeof(char) * 9)))
	return (1);
      error->file[i++][8] = '\0';
    }
  if (errorLines(ac, av))
    return (1);
  takeFile(ac, av, error);
  capitalizeFile(error);
  if (checkFile(error) || checkFile2(error) || errorLength(error))
    return (1);
  cleanFile(error);
  if (checkBoat(error) || checkBoat2(error) || checkBoat3(error))
    return (1);
  return (0);
}
