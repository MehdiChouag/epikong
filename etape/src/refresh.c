/*
** refresh.c for  in /home/brunne_r/Public/sdl_test/T2Rush1/etape_2/src
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Sun Mar  9 11:05:56 2014 brunne-r
** Last update Sun Mar  9 18:08:33 2014 Mehdi Chouag
*/

#include "epikong.h"
#include "surface.h"

void		prepare(t_graph *graph, t_map *imap)
{
  graph->image = SDL_CreateRGBSurface(SDL_HWSURFACE, graph->x, \
				      graph->y, 32, 0, 0, 0, 0);
  apply_fond(graph);
  aff_map(imap, graph);
  SDL_EnableKeyRepeat(100, 85);
}

int		oneturn(t_graph *graph, t_map *imap, int *ta, int *tb)
{
  SDL_Event	event;
  Uint8		*key;

  SDL_PollEvent(&event);
  key = SDL_GetKeyState(NULL);
  *ta = SDL_GetTicks();
  if (event.type == SDL_QUIT || key[SDLK_ESCAPE])
    return (0);
  if (event.type == SDL_KEYDOWN && key[SDLK_UP] && \
      (key[SDLK_RIGHT] || key[SDLK_LEFT]))
    jumpmove(key, imap);
  else if (event.type == SDL_KEYDOWN)
    move(event.key.keysym.sym, imap, graph);
  if (*ta - *tb < 60)
    SDL_Delay(60 - (*ta - *tb));
  *tb = SDL_GetTicks();
  gravity(imap);
  monster(imap);
  refresh(imap, graph);
  if (imap->map[imap->j.x][imap->j.y] == EEXIT)
    return (0);
  return (1);
}

void		mainLoop(t_graph *graph, t_map *imap)
{
  int		c;
  int		ta;
  int		tb;

  c = 1;
  tb = SDL_GetTicks();
  prepare(graph, imap);
  while (c)
    {
      if (SDL_Flip(graph->screen) == -1)
	exit(EXIT_FAILURE);
      c = oneturn(graph, imap, &ta, &tb);
    }
  game();
}
