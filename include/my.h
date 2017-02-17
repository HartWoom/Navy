/*
** my.h for  in /home/louis.hatte/PSU_2016_navy/include
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:51:38 2017 Louis HATTE
** Last update Fri Feb 17 14:04:51 2017 Antoine Hartwig
*/

#ifndef MY_H_
# define MY_H_

# ifndef READ_SIZE
#  define READ_SIZE 31
# endif /* !READ_SIZE */

#include <sys/types.h>
#include <sys/stat.h>
#include <ucontext.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include "gnl.h"

#define COORDS0 ((navy->coords[0] - 65) * 2) + 2
#define COORDS1 navy->coords[1] - 49 + 3
#define SENT0 ((navy->sent[0] - 65) * 2) + 2
#define SENT1 navy->sent[1] - 49 + 15

typedef struct	s_error
{
  char	**file;
}		t_error;

typedef struct  s_navy
{
  char  **map1;
  char  **map2;
  char	*key;
  char	*coords;
  char	*sent;
  int	other_pid;
  int	ships_sunk;
  int	ships;
}       t_navy;

void    my_putchar(char);
int     my_strlen(char *);
void    my_putstr(char *);
void	my_putn(char *, int);
void	my_puts(char *, char *);
void	my_putc(char *, char);
void    my_put_nbr(int);
int     my_getnbr(char *);
int     my_strcomp(char *, char *, int, int);
char    *my_strcat(char *, char *);
char    *my_strcopy(char *, int, int);
char    **my_strToWordTab(char *, char);
char    *my_wordTabToStr(char **, char);
void	display_map(t_navy *, int);
int	set_navy(t_navy *);
char    *my_split(char *, char *);
char    *my_concatenate(char *, char *, int, bool);
char    *my_readLine(int, char *, bool *);
char    *get_next_line(const int);
int	errorInput(int, char **);
void	hDisplay();
int	checkBoat3(t_error *);
int	checkBoat2(t_error *);
int	checkBoat(t_error *);
int	cleanFile(t_error *);
int	my_getnbr2(char *);
int	*lengthTabler();
int	errorLength(t_error *);
int	checkFile2(t_error *);
int	checkFile(t_error *);
int	capitalizeFile(t_error *);
int	takeFile(int, char **, t_error *);
int	errorLines(int, char **);
int	chooseAv(int, char **);
int	errorMap(int, char **, t_error *);
int	my_lines2(char *, char);
int	*my_columns2(char *, char, int);
char	**my_strToWordTab2(char *, char);
int	createMap(int, t_navy *, t_error *);
int	start_game(int, char **, t_navy *, t_error *);
int	host(int, t_navy *, t_error *);
int	client(int, char **, t_navy *, t_error *);
void	host_first_round(int, t_navy *, t_error *);
void	attack(int, t_navy *);
void	tell_if_hit_or_not(t_navy *, int);
int	encryption(t_navy *, int, char *);
int	send_signal(int, char, char *);
char	*my_swap(char *, int, int);
char	*my_simple_swap(char *);
int	update_map(t_navy *, int);
int	send_confirm(int, t_navy *);
void	simple_ping(int);
void	double_ping(int);
char	*my_strcapitalize(char *);
int	tell_victory_or_defeat(t_navy *, int);

#endif /* !MY_H_ */
