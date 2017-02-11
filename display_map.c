#include "include/my.h"

void	display_map(t_navy *navy, int map)
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
