/*
** updating_map.c for  in /home/louis.hatte/PSU_2016_navy
** 
** Made by Louis HATTE
** Login   <louis.hatte@epitech.net>
** 
** Started on  Thu Feb 16 14:00:50 2017 Louis HATTE
** Last update Thu Feb 16 14:00:51 2017 Louis HATTE
*/

#include "include/my.h"

int	my_glob;

void	Player1_part2(t_navy *navy, int x, int y)
{
  if (navy->map1[x][y] >= '2' && navy->map1[x][y] <= '5')
    {
      navy->map1[x][y] = 'x';
      send_signal(navy->other_pid, 'x', navy->key);
    }
  else if (navy->map1[x][y] == '.'
           || navy->map1[x][y] == 'o' || navy->map1[x][y] == 'x')
    if (navy->map1[x][y] == '.')
      {
        navy->map1[x][y] = 'o';
        send_signal(navy->other_pid, 'o', navy->key);
      }
}

int	Player1(t_navy *navy, int x, int y, int usr1)
{
  while (1)
    {
      pause();
      if (my_glob == 1)
	usr1++;
      if (my_glob == 2)
	{
	  navy->map1[navy->sent[1] - 49 + 15][((navy->sent[0] - 65) * 2) + 2]
	    = navy->key[usr1];
	  break;
	}
    }
  usleep(10000);
  Player1_part2(navy, x, y);
  my_putchar('\n');
  display_map(navy, 1);
  if (navy->ships_sunk == 14)
    return (10);
  if (navy->ships == 14)
    return (20);
  return (0);
}

void	Player2_part2(t_navy *navy, int usr1)
{
  while (1)
    {
      pause();
      if (my_glob == 1)
        usr1++;
      if (my_glob == 2)
        {
          navy->map2[navy->sent[1] - 49 + 15][((navy->sent[0] - 65) * 2) + 2]
            = navy->key[usr1];
          break;
        }
    }
}

int	Player2(t_navy *navy, int x, int y, int usr1)
{
  usleep(10000);
  if (navy->map2[x][y] >= '2' && navy->map2[x][y] <= '5')
    {
      navy->map2[x][y] = 'x';
      send_signal(navy->other_pid, 'x', navy->key);
    }
  else if (navy->map2[x][y] == '.'
	   || navy->map2[x][y] == 'o' || navy->map2[x][y] == 'x')
    if (navy->map2[x][y] == '.')
      {
	navy->map2[x][y] = 'o';
	send_signal(navy->other_pid, 'o', navy->key);
      }
  Player2_part2(navy, usr1);
  my_putchar('\n');
  display_map(navy, 2);
  if (navy->ships_sunk == 14)
    return (10);
  if (navy->ships == 14)
    return (20);
  return (0);
}

int		update_map(t_navy *navy, int player)
{
  int	x;
  int	y;
  int	usr1;

  x = 0;
  y = 0;
  usr1 = 0;
  if (navy->coords[0] >= '1' && navy->coords[0] <= '8')
    my_simple_swap(navy->coords);
  if (navy->sent[0] >= '1' && navy->sent[0] <= '8')
    my_simple_swap(navy->sent);
  while (navy->key[y] != navy->coords[0])
    y++;
  while (navy->key[x] != navy->coords[1])
    x++;
  y = 2 + (y * 2);
  x = 3 + (x - 8);
  if (player == 1)
    return (Player1(navy, x, y, usr1));
  if (player == 2)
    return (Player2(navy, x, y, usr1));
  return (0);
}
