/*
** my.h for  in /home/louis.hatte/Useful/Work
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Mon Dec 12 09:52:25 2016 Louis HATTE
** Last update Mon Jan 30 09:21:20 2017 Louis HATTE
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>

void	my_putchar(char);
int	my_strlen(char *);
void	my_putstr(char *);
void	my_put_nbr(int);
int	my_getnbr(char *);
int	my_strcomp(char *, char *, int, int);
char	*my_strcat(char *, char *);
char	*my_strcopy(char *, int, int);
char	**my_strToWordTab(char *, char);
char	*my_wordTabToStr(char **, char);

#endif /* !MY_H_ */
