/*
** get_next_line.h for  in /home/louis.hatte/CPE_2016_getnextline
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Wed Jan  4 15:34:35 2017 Louis HATTE
** Last update Sun Jan 15 13:00:55 2017 Louis HATTE
*/

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef READ_SIZE
#  define READ_SIZE 42
# endif /* !READ_SIZE */

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

char	*my_split(char *, char *);
char	*my_concatenate(char *, char *, int, bool);
char	*my_readLine(int, char *, bool *);
char	*get_next_line(const int);

#endif /* GET_NEXT_LINE */
