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
