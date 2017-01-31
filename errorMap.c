#include "include/my.h"

int	check_buffer(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if ((buffer[i] >= 'A' && buffer[i] <= 'H')
	  || (buffer[i] >= '1' && buffer[i] <= '8')
	  || (buffer[i] == ':')
	  || (buffer[i] == '\0'))
	i++;
      else
	return (-1);
    }
  my_putchar('D');
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
  my_putchar('L');
  if (check_buffer(buff) == -1)
    return (-1);
  my_putchar('M');
  return (0);
}

int	errorLength(char **av)
{
  
}

int	errorMap(char **av)
{
  errorLength(av);
}
