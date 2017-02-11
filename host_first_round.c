#include "include/my.h"

int	my_glob;

int	host_first_round_part2(t_navy *navy)
{
  static int	usr1 = 0;

  pause();
  if (my_glob == 1)
    usr1++;
  if (my_glob == 2 && usr1 == 1)
    {
      my_puts(navy->sent, ": hit");
      navy->ships++;
      return (1);
    }
  if (my_glob == 2 && usr1 == 2)
    {
      my_puts(navy->sent, ": missed");
      return (1);
    }
  return (0);
}

void	host_first_round(int ac, char **av, t_navy *navy)
{
  char	*coords;
  int	flag;

  flag = 0;
  my_putstr("enemy connected\n\n");
  createMap(ac, av, navy);
  my_putstr("\nattack:  ");
  usleep(15000);
  kill(navy->other_pid, SIGUSR1);
  usleep(8000);
  while ((coords = get_next_line(0)))
    {
      if (encryption(navy, navy->other_pid, coords) == 1)
	{
	  my_putstr("wrong position");
	  attack(navy->other_pid, navy);
	  flag = 1;
	}
      break;
    }
  if (flag == 0)
    {
      navy->sent = coords;
      while (1)
	{
	  if (host_first_round_part2(navy) == 1)
	    break;
	}
    }
}
