/*
** my_put.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 14:00:07 2017 Louis HATTE
** Last update Thu Feb 16 14:00:08 2017 Louis HATTE
*/

#include "include/my.h"

void	my_putn(char *str, int nb)
{
  my_putstr(str);
  my_put_nbr(nb);
  my_putchar('\n');
}

void	my_puts(char *str1, char *str2)
{
  my_putstr(str1);
  my_putstr(str2);
  my_putchar('\n');
}

void	my_putc(char *str, char c)
{
  my_putstr(str);
  my_putchar(c);
  my_putchar('\n');
}
