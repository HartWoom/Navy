/*
** start_game.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 14:00:41 2017 Louis HATTE
** Last update Fri Feb 17 11:50:51 2017 Antoine Hartwig
*/

#include "include/my.h"

int	my_glob = 0;

void	order(int sig, siginfo_t *info, void *context)
{
  static int	flag = 0;

  if (!(context = malloc(sizeof(ucontext_t))))
    return;
  getcontext(context);
  if (flag == 0)
    {
      my_glob = info->si_pid;
      flag = 1;
    }
  else if (sig == SIGUSR1 && flag == 1)
    my_glob = 1;
  else if (sig == SIGUSR2 && flag == 1)
    my_glob = 2;
}

int		host_part2(t_navy *navy)
{
  static int	flag = 0;
  static int	usr1 = 0;

  if (my_glob == 1)
    usr1++;
  if (my_glob == 2)
    {
      flag++;
      if (flag == 1)
	navy->coords[0] = navy->key[usr1];
      if (flag == 2)
	{
	  navy->coords[1] = navy->key[usr1];
	  tell_if_hit_or_not(navy, 2);
	  flag = update_map(navy, 1);
	  if (flag == 10 || flag == 20)
	    return (flag);
	  attack(navy->other_pid,  navy);
	  usr1 = 0;
	  return (flag);
	}
      usr1 = 0;
    }
  return (1);
}

int			host(int ac, char **av, t_navy *navy)
{
  struct sigaction	act;
  int			no_disp;

  no_disp = 0;
  my_putn("my_pid:  ", getpid());
  my_putstr("waiting for enemy connexion...\n");
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = order;
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  pause();
  if (set_navy(navy) == -1)
    return (84);
  host_first_round(ac, av, navy);
  while (1)
    {
      if (no_disp == 0)
	my_putstr("\nwaiting for enemy's attack...\n");
      no_disp = 1;
      pause();
      no_disp = host_part2(navy);
      if (no_disp == 10 || no_disp == 20)
	return (no_disp);
    }
  return (0);
}

int		client_part2(t_navy *navy)
{
  static int    flag = 0;
  static int    usr1 = 0;

  if (my_glob == 1)
    usr1++;
  if (my_glob == 2)
    {
      flag++;
      if (flag == 1)
	navy->coords[0] = navy->key[usr1];
      if (flag == 2)
        {
          navy->coords[1] = navy->key[usr1];
          tell_if_hit_or_not(navy, 1);
          attack(navy->other_pid,  navy);
	  flag = update_map(navy, 2);
	  usr1 = 0;
          return (flag);
        }
      usr1 = 0;
    }
  return (1);
}

int			client(int pid, int ac, char **av, t_navy *navy)
{
  struct sigaction	act;
  int			no_disp;

  no_disp = 0;
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = order;
  if (send_confirm(pid, navy) == -1)
    return (84);
  if (set_navy(navy) == -1)
    return (84);
  createMap(ac, av, navy);
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  pause();
  while (1)
    {
      if (no_disp == 0)
	my_putstr("\nwaiting for enemy's attack...\n");
      no_disp = 1;
      pause();
      no_disp = client_part2(navy);
      if (no_disp == 10 || no_disp == 20)
	return (no_disp);
    }
  return (0);
}
