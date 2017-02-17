#include "include/my.h"

int	tell_victory_or_defeat(t_navy *navy, int player)
{
  if (player == 2)
    my_putchar('\n');
  update_map(navy, player);
  display_map(navy, player);
  if (navy->ships_sunk == 3)
    return (10);
  if (navy->ships == 3)
    return (20);
  return (0);
}
