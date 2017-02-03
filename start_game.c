#include "include/my.h"
#include "include/global.h"

void	host_order(int sig)//, siginfo_t *info, void *context)
{
  if (sig == SIGUSR1)
    {
      my_glob.usr1++;
    }
  if (sig == SIGUSR2)
    {
      my_glob.usr2++;
    }
}

void	client_order(int sig)//, siginfo_t *info, void *context)
{
  if (sig == SIGUSR1)
    {
      my_glob.usr1++;
    }
  if (sig == SIGUSR2)
    {
      my_glob.usr2++;
    }
}

void			host(char *key)
{
  struct sigaction	act;
  char			*coords;

  my_putstr("my_pid:  ");
  my_put_nbr(getpid());
  my_putstr("\nwaiting for ennemy connection...\n");
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = host_order;
  if (sigaction(SIGUSR1, &act, NULL) < 0)
    return;
  if (sigaction(SIGUSR2, &act, NULL) < 0)
    return;
  while (1)
    {
      usleep(10000);
      //      printf("pid: %i usr1: %i usr2: %i\n", getpid(), my_glob.usr1, my_glob.usr2);
      if (my_glob.usr2 == 1 && my_glob.usr1 <= 15)
	{
	  my_putchar(key[my_glob.usr1]);
	  my_glob.usr1 = 0;
	  my_glob.usr2 = 0;
	}
      else if (my_glob.usr2 == 1 && my_glob.usr1 == 9)
	{
	  my_glob.usr1 = 0;
	  my_glob.usr2 = 0;
	  my_putstr("enemy connected\n");
	}
    }
}

void			client(char *pid, char *key)
{
  struct sigaction	act;
  char			*coords;
  int			i;

  my_putstr("my_pid:  ");
  my_put_nbr(getpid());
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = client_order;
  while (++i != 10)
    {
      if (kill(my_getnbr(pid), SIGUSR1) == -1)
	return;
      usleep(10000);
    }
  kill(my_getnbr(pid), SIGUSR2);
  my_putstr("\nsuccessfully connected\n");
  if (sigaction(SIGUSR1, &act, NULL) < 0)
    return;
  if (sigaction(SIGUSR2, &act, NULL) < 0)
    return;
  my_putstr("\nattack: ");
  while ((coords = get_next_line(0)))
    {
      encryption(pid, coords);
      my_putstr("\nattack: ");
    }
}

int	start_game(int ac, char **av)
{
  char	*key;

  if ((key = malloc(sizeof(char) * 17)) == NULL)
    return (-1);
  key = "ABCDEFGH12345678";
  if (ac == 2)
    host(key);
  else if (ac == 3)
    client(av[1], key);
  return (0);
}
