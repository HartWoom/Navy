/*
** help.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 10:15:32 2017 Louis HATTE
** Last update Tue Jan 31 12:08:05 2017 Louis HATTE
*/

#include "include/my.h"

void	hDisplay()
{
  my_putstr("USAGE\n");
  my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\tfirst_player_pid\t");
  my_putstr("only for the 2nd player.  pid of the first player.\n");
  my_putstr("\tnavy_positions\t\t");
  my_putstr("file representing the positions of the ships.\n");
}
