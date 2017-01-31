/*
** errorMap.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:23:37 2017 Louis HATTE
** Last update Tue Jan 31 13:07:46 2017 Louis HATTE
*/

#include "include/my.h"
#include "include/get_next_line.h"

int	errorLength(int ac, char **av)
{
  int	fd;
  int	*length;
  char	*line;
  int	a;
  int	i;
  int	j;

<<<<<<< HEAD
  j = 7;
=======
  fd = chooseAv(ac, av);
  if ((length = lengthTabler()) == NULL)
    return (1);
>>>>>>> a4d743195996fe74a2036869034477be31a2b14c
  i = 0;
  a = 0;
  while (line = get_next_line(fd))
    {
<<<<<<< HEAD
      if (((i % j) == 0) && (i != 0))
	if (buffer[i] != '\n')
	  return (-1);
      if ((buffer[i] >= 'A' && buffer[i] <= 'H')
	  || (buffer[i] >= '1' && buffer[i] <= '8')
	  || (buffer[i] == ':')
	  || (buffer[i] == '\n'))
	i++;
      else
	return (-1);
      j++;
    }
  if (i != 32)
    return (-1);
=======
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
      (c >= '1' && c <= '8') ||
      (c == ':') || (c == '\n'))
    return (1);
>>>>>>> a4d743195996fe74a2036869034477be31a2b14c
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
<<<<<<< HEAD
  if (check_buffer(buff) == -1)
    return (-1);
=======
  if (!(characters(buff[0])) || lines != 4)
    return (1);
>>>>>>> a4d743195996fe74a2036869034477be31a2b14c
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
  if (errorLines(ac, av) || errorLength(ac, av))
    return (1);
  return (0);
}
