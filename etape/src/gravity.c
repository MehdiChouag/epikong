/*
** gravity.c for  in /home/brunne_r/Public/sdl_test/T2Rush1/etape_2/src
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Sun Mar  9 10:28:50 2014 brunne-r
** Last update Sun Mar  9 16:14:48 2014 brunne-r
*/

#include "epikong.h"

static int	ijump = 0;

void		isJump(void)
{
  ijump = 2;
}

void		isPossible(t_map *imap, int x, int y, int coeff)
{
  int		i;

  i = 0;
  while (i < coeff)
    {
      ++x;
      if (imap->map[x][y] != EBLANK)
	{
	  --x;
	  i = coeff;
	}
      ++i;
    }
  imap->j.x = x;
  imap->j.y = y;
}

void		gravity(t_map *imap)
{
  static int	cgravity = 0;
  int		x;
  int		y;

  x = imap->j.x;
  y = imap->j.y;
  if (imap->map[x + 1][y] == EBLANK && imap->map[x][y] != ELADDER)
    {
      if (ijump == 0)
	{
	  isPossible(imap, x, y, cgravity);
	  if (cgravity <= 1)
	    cgravity++;
	  else
	    cgravity *= 2;
	}
      else
	{
	  ijump--;
	}
    }
  else
    cgravity = 1;
}
