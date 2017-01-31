/*
** get_next_line.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 13:08:22 2017 Louis HATTE
** Last update Tue Jan 31 13:08:24 2017 Louis HATTE
*/

#include "get_next_line.h"

char	*my_split(char *str, char stat[])
{
  int	i;
  int	tmp;
  char	*line;

  i = 0;
  while (str[i] != '\n' && ++i);
  if (!(line = malloc(sizeof(char) * i + 1)))
    return (NULL);
  line[(tmp = i)] = '\0';
  while (i-- > 0)
    line[i] = str[i];
  if (str[++tmp] != '\0')
    {
      i = 0;
      while (str[tmp] != '\0')
	stat[i++] = str[tmp++];
      stat[i] = '\0';
    }
  else if (!(i = 0))
    while (i < READ_SIZE)
      stat[i++] = '\0';
  free(str);
  return (line);
}

char	*my_concatenate(char *a, char *b, int bools, bool finished)
{
  char	*line;
  int	i;
  int	j;

  i = (j = 0);
  if (b == NULL)
    return NULL;
  while (a && a[i] != '\0' && ++i);
  while (b && b[j] != '\0' && ++i && ++j);
  if (finished || !(line = malloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = (j = 0);
  while (a && a[i] != '\0')
    line[i] = a[i++];
  while (b && b[j] != '\0')
    line[i++] = b[j++];
  line[i] = '\0';
  if (a && (!bools || bools == 2))
    free(a);
  if (b && (bools == 1 || bools == 2))
    free(b);
  return (line);
}

char	*my_readLine(int fd, char stat[], bool *finished)
{
  char	*line;
  char	buff[READ_SIZE + 1];
  int	r;
  int	i;

  i = 0;
  line = NULL;
  while ((r = read(fd, buff, READ_SIZE)) != 0)
    {
      if (r < 0)
	return (NULL);
      buff[r] = '\0';
      line = my_concatenate(line, buff, -1, false);
      while (line[i] != '\0')
	if (line[i++] == '\n')
	  return (my_split(line, stat));
    }
  *finished = true;
  while (r < READ_SIZE)
    stat[r++] = '\0';
  return (line);
}

char            *get_next_line(const int fd)
{
  static bool	defined = true;
  static bool   finished = false;
  static char	stat[READ_SIZE + 1];
  char		*tmp;
  int		i;

  if (fd < 0)
    return (NULL);
  if (defined && !(i = 0))
    {
      while (i < READ_SIZE + 1)
	stat[i++] = '\0';
      defined = false;
    }
  tmp = my_concatenate(NULL, stat, -1, finished);
  if (*stat && (i = -1))
    {
      while (stat[++i] != '\0')
	if (stat[i] == '\n')
	  return (my_split(tmp, stat));
    }
  return (my_concatenate(tmp, my_readLine(fd, stat, &finished), 2, finished));
}
