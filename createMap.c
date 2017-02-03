/*
** createMap.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb  2 13:37:17 2017 Louis HATTE
** Last update Fri Feb  3 14:32:04 2017 Louis HATTE
*/

#include "include/my.h"

int	find_char(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

char	**charNb(char **map, char *str, int a)
{
  int	tmp;
  int	i;

  tmp = a;
  i = 0;
  if (str[2] == str[5])
    {
      while (tmp > 0)
      	{
	  map[str[3] - 46 + i]
	    [str[2] - (str[2] - (2 * str[2] % 63)) - 2] = a + 48;
      	  i = i + 1;
      	  tmp--;
      	}
    }
  else
    {
      while (tmp > 0)
	{
	  map[str[3] - 46]
	    [str[2] - (str[2] - (2 * str[2] % 63)) - 2 + i] = a + 48;
	  i = i + 2;
	  tmp--;
	}
    }
  return (map);
}

char	**nbChar(char **map, char *str, int a)
{
  
  return (map);
}

char	**putBoats(int ac, char **av, char **map)
{
  char	*str;
  int	a;
  int	fd;

  if (ac == 2)
    fd = open(av[1], O_RDONLY);
  else
    fd = open(av[2], O_RDONLY);
  while  ((str = get_next_line(fd)))
    {
      a = my_getnbr2(str);
      if (find_char(str[2]))
	map = nbChar(map, str, a);
      else
	map = charNb(map, str, a);
    }
  close(fd);
  return (map);
}

void		createMap(int ac, char **av)
{
  int		fd;
  char		buff[396];
  t_navy	*navy;

  navy = malloc(sizeof(t_navy));
  fd = open("map", O_RDONLY);
  read(fd, buff, 396);
  navy->map1 = my_strToWordTab2(buff, '\n');
  navy->map2 = my_strToWordTab2(buff, '\n');
  close(fd);
  if (ac == 2)
    navy->map1 = putBoats(ac, av, navy->map1);
  else
    navy->map2 = putBoats(ac, av, navy->map2);


  int   j = 0;
  while (j < 25)
    my_putstr(navy->map1[j++]);
}
