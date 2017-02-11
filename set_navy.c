#include "my.h"

int	set_navy(t_navy *navy)
{
  if ((navy->key = malloc(sizeof(char) * 20)) == NULL)
    return (-1);
  navy->key = "ABCDEFGH12345678xo.";
  if ((navy->coords = malloc(sizeof(char) * 3)) == NULL)
    return (-1);
  navy->coords[2] = '\0';
  navy->ships_sunk = 0;
  navy->ships = 0;
  return (0);
}
