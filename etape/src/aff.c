/*
** aff.c for  in /home/brunne_r/Public/sdl_test
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Fri Mar  7 23:08:40 2014 brunne-r
** Last update Sun Mar  9 16:14:28 2014 brunne-r
*/

#include "epikong.h"
#include "surface.h"

void		aff_map(t_map *imap, t_graph *graph)
{
  int		i;
  int		j;

  i = 0;
  while (i < imap->height - 1)
    {
      j = 0;
      while (j < imap->width)
	{
	  if (imap->map[i][j] != EBLANK && \
	      (imap->map[i][j] != EENTRY && imap->map[i][j] != EMONSTER))
	    {
	      apply_surface(j * BLOCK, i * BLOCK, \
			    graph->texture[imap->map[i][j]], graph->image);
	    }
	  ++j;
	}
      ++i;
    }
}

void		aff_dyn(t_map *imap, t_graph *graph)
{
  int		i;

  i = 0;
  apply_surface(imap->j.y * BLOCK, imap->j.x * BLOCK, \
		graph->texture[EENTRY], graph->screen);
  while (i < imap->nbMonsters)
    {
      apply_surface(imap->monsters[i].y * BLOCK, \
		    imap->monsters[i].x * BLOCK, \
		    graph->texture[EMONSTER], graph->screen);
      ++i;
    }
}

void	refresh(t_map *imap, t_graph *graph)
{
  apply_surface(0, 0, graph->image, graph->screen);
  aff_dyn(imap, graph);
}

void		apply_fond(t_graph *graph)
{
  SDL_Surface	*fd;
  double	rx;
  double	ry;

  rx = (double)graph->x / 1920.0;
  ry = (double)graph->y / 1080.0;
  fd = IMG_Load("./images/fond.jpg");
  fd = rotozoomSurfaceXY(fd, 0, rx, ry, 1);
  apply_surface(0, 0, fd, graph->image);
  SDL_FreeSurface(fd);
}
