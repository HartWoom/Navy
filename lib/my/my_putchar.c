/*
** my_putchar.c for  in /home/louis.hatte/FuturLib
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Oct 11 08:25:52 2016 Louis HATTE
** Last update Sun Jan 22 17:32:07 2017 Louis HATTE
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
