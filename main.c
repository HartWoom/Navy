#include "include/my.h"

int	error_management(int ac, char **av)
{
  if (ac != 2 && ac != 3)
    return (-1);
  if (my_str_cmp(av[1], "-h") == 0)
    {
      display_h();
      return (0);
    }
  /* if (ac == 2) */
  /*   check_map(av[1]); */
  /* else */
  /*   check_map(av[2]); */
  return (0);
}

int	main(int ac, char **av)
{
  if (error_management(ac, av) == -1)
    return (84);
  return (0);
}
