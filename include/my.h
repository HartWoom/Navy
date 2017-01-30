/*
** my.h for navy in /home/antoine.hartwig/Epitech/PSU_2016/PSU_2016_navy_bootstrap
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Mon Jan 30 09:10:43 2017 Antoine Hartwig
** Last update Mon Jan 30 18:54:45 2017 Antoine Hartwig
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_map
{
  char	**pos1;
  char	**pos2;
}	t_map;

void	my_putstr(char *);
void	my_put_nbr(int);
void	my_putchar(char);
int	my_getnbr(char *);
int	my_str_cmp(char *, char *);
void	display_h();
int	gather_map(char *);

#endif /* !MY_H_ */
