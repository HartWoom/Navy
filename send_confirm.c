/*
** send_confirm.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 14:00:26 2017 Louis HATTE
** Last update Thu Feb 16 14:00:27 2017 Louis HATTE
*/

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
