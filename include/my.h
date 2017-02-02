/*
** my.h for  in /home/louis.hatte/PSU_2016_navy/include
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:51:38 2017 Louis HATTE
** Last update Thu Feb  2 13:20:13 2017 Louis HATTE
*/

#ifndef MY_H_
# define MY_H_

# ifndef READ_SIZE
#  define READ_SIZE 42
# endif /* !READ_SIZE */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_coords
{
  int	size;
  int	char1;
  int	char2;
  int	char3;
  int	char4;
}	t_coords;

void    my_putchar(char);
int     my_strlen(char *);
void    my_putstr(char *);
void    my_put_nbr(int);
int     my_getnbr(char *);
int     my_strcomp(char *, char *, int, int);
char    *my_strcat(char *, char *);
char    *my_strcopy(char *, int, int);
char    **my_strToWordTab(char *, char);
char    *my_wordTabToStr(char **, char);

char    *my_split(char *, char *);
char    *my_concatenate(char *, char *, int, bool);
char    *my_readLine(int, char *, bool *);
char    *get_next_line(const int);

int	errorInput(int, char **);

void	hDisplay();

int	my_getnbr2(char *);
int	*lengthTabler();

int	errorLength(int, char **);
int	characters(char);
int	errorLines(int, char **);
int	chooseAv(int, char **);
int	errorMap(int, char **);

int	check_coords(int);
int	check_coords_part2(t_coords *);

#endif /* !MY_H_ */
