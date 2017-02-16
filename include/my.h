/*
** my.h for  in /home/louis.hatte/PSU_2016_navy/include
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Tue Jan 31 09:51:38 2017 Louis HATTE
** Last update Thu Feb 16 15:04:53 2017 Antoine Hartwig
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

typedef struct	s_coords
{
  int	size;
  int	char1;
  int	char2;
  int	char3;
  int	char4;
}	t_coords;

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
int	my_getnbr2(char *);
int	*lengthTabler();
int	errorLength(int, char **);
int	characters(char);
int	errorLines(int, char **);
int	chooseAv(int, char **);
int	errorMap(int, char **);
int     check_coords(int);
int     check_coords_part2(t_coords *);
int	my_lines2(char *, char);
int	*my_columns2(char *, char, int);
char	**my_strToWordTab2(char *, char);
int	createMap(int, char **, t_navy *);
int	start_game(int, char **, t_navy *);
void	host_first_round(int, char **, t_navy *);
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

#endif /* !MY_H_ */
