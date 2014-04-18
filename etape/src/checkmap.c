/*
** checkmap.c for  in /home/brunne_r/Public/sdl_test
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Fri Mar  7 21:30:06 2014 brunne-r
** Last update Sun Mar  9 18:02:37 2014 brunne-r
*/

#include "epikong.h"

int	inValid(char c)
{
  char	valid[NBC];
  int	i;

  valid[0] = WALL;
  valid[1] = LADDER;
  valid[2] = MONSTER;
  valid[3] = EXIT;
  valid[4] = ENTRY;
  valid[5] = BLANK;
  valid[6] = KEY;
  i = 0;
  while (i < NBC)
    {
      if (valid[i] == c)
	i = 10;
      else
	++i;
    }
  if (i == 10)
    return (1);
  else
    return (-1);
}

int	knownCarac(char **map, int *entry, int *exit)
{
  int	i;
  int	j;
  int	c;

  i = 0;
  c = -1;
  *exit = 0;
  *entry = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (inValid(map[i][j]) < 0)
	    c = map[i][j];
	  if (map[i][j] == ENTRY)
	    *entry = 1;
	  if (map[i][j] == EXIT)
	    *exit = 1;
	  ++j;
	}
      ++i;
    }
  return (c);
}

int	checkWall(char **map)
{
  int	i;
  int	j;

  i = 0;
  while (map[i])
    ++i;
  --i;
  j = 0;
  while (map[0][j] && map[i][j])
    {
      if (map[0][j] != WALL || map[i][j] != WALL)
	return (-1);
      ++j;
    }
  j = 0;
  i = strlen(map[0]) - 1;
  while (map[j] && map[j][0] && map[j][i])
    {
      if (map[j][0] != WALL || map[j][i] != WALL)
	return (-1);
      ++j;
    }
  return (1);
}

int		isSquare(char **map)
{
  int		i;
  unsigned int	len;

  i = 0;
  len = strlen(map[0]);
  while (map[i])
    {
      if (strlen(map[i]) != len)
	return (-1);
      ++i;
    }
  return (1);
}

int	checkMap(char **map)
{
  int	entry;
  int	exit;
  int	c;
  int	e;

  e = 0;
  if (isSquare(map) < 0)
    e = fprintf(stderr, "map is not a square\n");
  if ((c = knownCarac(map, &entry, &exit)) >= 0)
    e = fprintf(stderr, "%c : unknow caracter\n", c);
  if (entry != 1 || exit == 0)
    e = fprintf(stderr, \
		"map must have only one entry and at least one exit\n");
  if (checkWall(map) < 0)
    e = fprintf(stderr, "the sides of the map must be fill of walls\n");
  return ((e > 0) ? (-1) : (1));
}
