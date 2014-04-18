/*
** kup.c for  in /home/brunne_r/Public/sdl_test/T2Rush1/etape_2/src
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Sun Mar  9 11:26:03 2014 brunne-r
** Last update Sun Mar  9 16:27:14 2014 brunne-r
*/

#include "epikong.h"

void	ladder_up(int x, int y, t_map *imap)
{
  if (imap->map[x - 1][y] == ELADDER || \
      (imap->map[x][y] == ELADDER && imap->map[x - 1][y] != EWALL))
    {
      imap->j.x--;
    }
}

void	initxy(t_map *imap, int *x, int *y)
{
  *x = imap->j.x;
  *y = imap->j.y;
}

void	jumpmove(Uint8 *k, t_map *imap)
{
  int	my;
  int	i;
  int	x;
  int	y;

  initxy(imap, &x, &y);
  my = ((k[SDLK_LEFT]) ? (-1) : (1));
  if (imap->map[x - 1][y] == EBLANK && imap->map[x + 1][y] != EBLANK)
    {
      isJump();
      --x;
      i = 0;
      while (i < 2)
	{
	  if (imap->map[x][y + my] == EBLANK || imap->map[x][y + my] == ELADDER)
	    y += my;
	  if (imap->map[x][y] != EBLANK)
	    i = 2;
	  ++i;
	}
    }
  imap->j.x = x;
  imap->j.y = y;
}

void	jump(int x, int y, t_map *imap)
{
  int	i;

  i = 0;
  while (i < 2)
    {
      --x;
      if (imap->map[x][y] == ELADDER ||
	  imap->map[x][y] == EBLANK)
	++i;
      else
	{
	  i = 2;
	  ++x;
	}
    }
  isJump();
  imap->j.x = x;
  imap->j.y = y;
}
