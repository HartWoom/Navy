#include "include/my.h"

int	check_buffer(char *buffer)
{
  int	i;
  int	j;

  j = 7;
  i = 0;
  while (buffer[i] != '\0')
    {
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
  return (0);
}

int	gather_map(char *file)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 29)) == NULL)
    return (-1);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, buff, 1024) == -1)
    return (-1);
  close(fd);
  if (check_buffer(buff) == -1)
    return (-1);
  return (0);
}
