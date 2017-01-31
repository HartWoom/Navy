/*
** my.h for  in /home/louis.hatte/PSU_2016_navy/include
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:51:38 2017 Louis HATTE
** Last update Tue Jan 31 12:59:44 2017 Louis HATTE
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

int	errorInput(int, char **);

void	hDisplay();

int	my_getnbr2(char *);
int	*lengthTabler();

int	errorLength(int, char **);
int	characters(char);
int	errorLines(int, char **);
int	chooseAv(int, char **);
int	errorMap(int, char **);

#endif /* !MY_H_ */
