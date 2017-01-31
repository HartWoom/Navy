/*
** my_put_nbr.c for  in /home/louis.hatte/CPool_Day03
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Oct  6 08:30:53 2016 Louis HATTE
** Last update Sun Jan 22 17:35:12 2017 Louis HATTE
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	nbsave;
  int	denominateur;

  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  nbsave = nb;
  denominateur = 1;
  while (nb >= 10)
    {
      nb = nb / 10;
      denominateur = denominateur * 10;
    }
  nb = nbsave;
  while (denominateur >= 10)
    {
      my_putchar(nb / denominateur + 48);
      nb = nb % denominateur;
      denominateur = denominateur / 10;
    }
  my_putchar(nb + 48);
}
