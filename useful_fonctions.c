#include "include/my.h"

void    display_map(t_navy *navy, int map)
{
  int       j;

  j = 0;
  if (map == 1)
    while (j < 23)
      my_putstr(navy->map1[j++]);
  else if (map == 2)
    while (j < 23)
      my_putstr(navy->map2[j++]);
}

char    *my_strcapitalize(char *str)
{
  int   i;

  if (str[0] >= '1' && str[0] <= '8')
    str = my_simple_swap(str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'h')
        str[i] -= 32;
      i++;
    }
  return (str);
}

char    *my_simple_swap(char *str)
{
  char tmp;

  tmp = str[0];
  str[0] = str[1];
  str[1] = tmp;
  return (str);
}

void    simple_ping(int pid)
{
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR2);
  usleep(10000);
}

void    double_ping(int pid)
{
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR2);
  usleep(10000);
}
