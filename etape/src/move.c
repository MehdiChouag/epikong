/*
** move.c for  in /home/brunne_r/Public/sdl_test/T2Rush1/etape_2/src
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Sun Mar  9 11:03:30 2014 brunne-r
** Last update Sun Mar  9 17:50:07 2014 brunne-r
*/

#include "epikong.h"
#include "surface.h"

void		move_left(int x, int y, t_map *imap, t_graph *graph)
{
  graph->texture[EENTRY] = graph->left;
  if (y > 0 && imap->map[x][y - 1] != EWALL)
    {
      imap->j.y--;
    }
}

void		move_right(int x, int y, t_map *imap, t_graph *graph)
{
  graph->texture[EENTRY] = graph->right;
  if (y < imap->width  && imap->map[x][y + 1] != EWALL)
    {
      imap->j.y++;
    }
}

void		move_up(int x, int y, t_map *imap, t_graph *graph)
{
  (void)graph;
   if (imap->map[x - 1][y] == ELADDER || \
      (imap->map[x][y] == ELADDER && imap->map[x - 1][y] != EWALL))
     ladder_up(x, y, imap);
   else if (imap->map[x + 1][y] != EBLANK)
     jump(x, y, imap);
}

void		move_down(int x, int y, t_map *imap, t_graph *graph)
{
  (void)graph;
  if (imap->map[x + 1][y] == ELADDER || \
      (imap->map[x][y] == ELADDER && imap->map[x + 1][y] != EWALL))
    {
      imap->j.x++;
    }
}

void		move(int key, t_map *imap, t_graph *graph)
{
  void		(*fp[4])(int, int, t_map*, t_graph *);

  key -= 273;
  fp[0] = move_up;
  fp[1] = move_down;
  fp[3] = move_left;
  fp[2] = move_right;
  if (key < 4 && key >= 0)
    fp[key](imap->j.x, imap->j.y, imap, graph);
  if (imap->map[imap->j.x][imap->j.y] == EKEY)
    {
      imap->map[imap->j.x][imap->j.y] = EBLANK;
      apply_fond(graph);
      aff_map(imap, graph);
    }
}
