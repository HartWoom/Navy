/*
** createMap.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb  2 13:37:17 2017 Louis HATTE
** Last update Fri Feb 17 13:12:34 2017 Louis HATTE
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

char	**putBoats(char **map, t_error *error)
{
  int	j;

  while  (j < 4)
    {
      if ((map = putBoat(map, error->file[j],
			 my_getnbr2(error->file[j]))) == NULL)
	return (NULL);
      j++;
    }
  return (map);
}

int		createMap(int ac, t_navy *navy, t_error *error)
{
  int		fd;
  char		buff[396];

  fd = open("map", O_RDONLY);
  read(fd, buff, 396);
  navy->map1 = my_strToWordTab2(buff, '\n');
  navy->map2 = my_strToWordTab2(buff, '\n');
  close(fd);
  if (ac == 2)
    {
      if ((navy->map1 = putBoats(navy->map1, error)) == NULL)
	return (1);
      display_map(navy, 1);
    }
  else
    {
      if ((navy->map2 = putBoats(navy->map2, error)) == NULL)
	return (1);
      display_map(navy, 2);
    }
  return (0);
}
