#include "include/my.h"

int     start_game(int ac, char **av, t_navy *navy)
{
  if (ac == 2)
    {
      if (host(ac, av, navy) == 20)
        {
          my_putstr("\nI won\n");
          return (0);
        }
      my_putstr("\nEnemy won\n");
      return (1);
    }
  else if (ac == 3)
    {
      if (client(my_getnbr(av[1]), ac, av, navy) == 20)
        {
          my_putstr("\nI won\n");
          return (0);
        }
      my_putstr("\nEnemy won\n");
      return (1);
    }
  return (0);
}
