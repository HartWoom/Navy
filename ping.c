#include "include/my.h"

void	simple_ping(int pid)
{
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR2);
  usleep(10000);
}

void	double_ping(int pid)
{
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR2);
  usleep(10000);
}
