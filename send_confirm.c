#include "include/my.h"

int	send_confirm(int pid, t_navy *navy)
{
  if (kill(pid, SIGUSR1) == -1)
    return (-1);
  navy->other_pid = pid;
  my_putn("my_pid:  ", getpid());
  my_putstr("successfully connected\n\n");
  return (0);
}
