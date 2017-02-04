/*
** createMap.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb  2 13:37:17 2017 Louis HATTE
** Last update Sat Feb  4 14:39:28 2017 Louis HATTE
*/

#include "include/my.h"

char	**horizontalBoat(char **map, char *str, int a)
{
  int	i;
  int	tmp;

  i = 0;
  tmp = a;
  while (tmp > 0)
    {
      if ((map[str[3] - 46]
	   [str[2] - (str[2] - (2 * str[2] % 63)) - 2 + i]) != '.')
	return (NULL);
      map[str[3] - 46]
	[str[2] - (str[2] - (2 * str[2] % 63)) - 2 + i] = a + 48;
      i = i + 2;
      tmp--;
    }
  return (map);
}

char	**verticalBoat(char **map, char *str, int a)
{
  int	i;
  int	tmp;

  i = 0;
  tmp = a;
  while (tmp > 0)
    {
      if (map[str[3] - 46 + i]
	  [str[2] - (str[2] - (2 * str[2] % 63)) - 2] != '.')
	return (NULL);
      map[str[3] - 46 + i++]
	[str[2] - (str[2] - (2 * str[2] % 63)) - 2] = a + 48;
      tmp--;
    }
  return (map);
}

char	**putBoat(char **map, char *str, int a)
{
  if (str[2] == str[5])
    {
      if ((map = verticalBoat(map, str, a)) == NULL)
	return (NULL);
    }
  else
    {
      if ((map = horizontalBoat(map, str, a)) == NULL)
	return (NULL);
    }
  return (map);
}

char	**putBoats(int ac, char **av, char **map)
{
  char	*str;
  int	i;
  int	fd;

  fd = chooseAv(ac, av);
  i = 0;
  while  ((str = get_next_line(fd)))
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= 'a' && str[i] <= 'h')
	    str[i] = str[i] + 32;
	  i++;
	}
      if (str[2] >= '0' && str[2] <= '9')
	{
	  str = my_swap(str, 2, 3);
	  str = my_swap(str, 5, 6);
	}
      if ((map = putBoat(map, str, my_getnbr2(str))) == NULL)
	return (NULL);
    }
  close(fd);
  return (map);
}

int		createMap(int ac, char **av)
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
    {
      if ((navy->map1 = putBoats(ac, av, navy->map1)) == NULL)
	return (1);
    }
  else
    {
      if ((navy->map2 = putBoats(ac, av, navy->map2)) == NULL)
	return (1);
    }
  int	j = 0;
  while (j < 25)
    my_putstr(navy->map1[j++]);
  return (0);
}
