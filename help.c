#include "include/my.h"

void	display_h()
{
  my_putstr("USAGE\n");
  my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\tfirst_player_pid\t");
  my_putstr("only for the 2nd player.  pid of the first player,\n");
  my_putstr("\tnavy_positions\t\t");
  my_putstr("file representing the positions of the ships.\n");
}
