/*
** transform.c for  in /home/brunne_r/Public/sdl_test/T2Rush1
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Sat Mar  8 15:01:55 2014 brunne-r
** Last update Sun Mar  9 17:59:38 2014 brunne-r
*/

#include "epikong.h"

void	mapcopy(int *t, char *s)
{
  int	i;
  int	corres[128];

  i = 0;
  corres[BLANK] = EBLANK;
  corres[WALL] = EWALL;
  corres[LADDER] = ELADDER;
  corres[MONSTER] = EMONSTER;
  corres[EXIT] = EEXIT;
  corres[ENTRY] = EENTRY;
  corres[KEY] = EKEY;
  while (s[i])
    {
      t[i] = corres[(int)(s[i])];
      ++i;
    }
}

int	**transformMap(char **map, int *w)
{
  int	h;
  int	**imap;
  int	i;

  *w = strlen(map[0]);
  h = 0;
  while (map[h])
    ++h;
  imap = malloc(sizeof(int*) * (h + 1));
  if (imap)
    {
      i = 0;
      while (i < h)
	{
	  if ((imap[i] = malloc(sizeof(int) * *w)) != NULL)
	    {
	      mapcopy(imap[i], map[i]);
	      ++i;
	    }
	}
      imap[i] = NULL;
    }
  return (imap);
}

void	freeiMap(t_map *imap)
{
  int	i;

  i = 0;
  while (imap->map[i])
    {
      free(imap->map[i]);
      ++i;
    }
  free(imap->map);
  free(imap->monsters);
}

void	initMonsterMap(t_map *imap, int nbm)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  imap->monsters = malloc(sizeof(t_movable) * (nbm));
  if (!imap->monsters)
    return ;
  x = 0;
  while (x < (imap->height - 1))
    {
      y = 0;
      while (y < imap->width)
	{
	  if (imap->map[x][y] == EMONSTER)
	    {
	      imap->monsters[i].x = x;
	      imap->monsters[i].flag = 1;
	      imap->monsters[i++].y = y;
	      imap->map[x][y] = EBLANK;
	    }
	  ++y;
	}
      ++x;
    }
}

void	initiMap(t_map *imap)
{
  int	i;
  int	j;
  int	m;

  i = 0;
  m = 0;
  while (i < (imap->height - 1))
    {
      j = 0;
      while (j < (imap->width))
	{
	  if (imap->map[i][j] == EENTRY)
	    {
	      imap->j.x = i;
	      imap->j.y = j;
	      imap->map[i][j] = EBLANK;
	    }
	  else if (imap->map[i][j] == EMONSTER)
	    ++m;
	  ++j;
	}
      ++i;
    }
  initMonsterMap(imap, m);
  imap->nbMonsters = m;
}
