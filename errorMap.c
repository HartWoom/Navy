/*
** errorMap.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:23:37 2017 Louis HATTE
** Last update Sat Feb  4 10:14:31 2017 Louis HATTE
*/

#include "include/my.h"

int	errorLength(int ac, char **av)
{
  int	fd;
  int	*length;
  char	*line;
  int	a;
  int	i;

  fd = chooseAv(ac, av);
  if ((length = lengthTabler()) == NULL)
    return (1);
  i = 0;
  a = 0;
  while ((line = get_next_line(fd)))
    {
      a = my_getnbr2(line);
      while (a != length[i] && ++i < 4);
      if (a == length[i])
	length[i] = 1;
      i = 0;
    }
  while (length[i++] == 1);
  if (i != 5)
    return (1);
  return (0);
}

int	characters(char c)
{
  if ((c >= 'A' && c <= 'H') ||
      (c >= 'a' && c <= 'h') ||
      (c >= '1' && c <= '8') ||
      (c == ':') || (c == '\n'))
    return (1);
  return (0);
}

int	errorLines(int ac, char **av)
{
  char	buff[1];
  int	lines;
  int	fd;

  lines = 0;
  fd = chooseAv(ac, av);
  while (read(fd, buff, 1) != 0 && characters(buff[0]))
    {
      if (buff[0] == '\n')
	lines++;
    }
  close(fd);
  if (!(characters(buff[0])) || lines != 4)
    return (1);
  return (0);
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

int	errorMap(int ac, char **av)
{
  if (errorLines(ac, av) ||
      errorLength(ac, av) ||
      check_coords(chooseAv(ac, av)))
    return (1);
  return (0);
}
