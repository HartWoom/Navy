#include "include/my.h"

char	*my_simple_swap(char *str)
{
  char tmp;

  tmp = str[0];
  str[0] = str[1];
  str[1] = tmp;
  return (str);
}
