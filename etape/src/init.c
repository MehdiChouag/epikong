/*
** init.c for init.c in /home/chouag_m/rendu/T2Rush1
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Sat Mar  8 14:59:06 2014 Mehdi Chouag
** Last update Sun Mar  9 17:51:41 2014 brunne-r
*/

#include "surface.h"
#include "epikong.h"

SDL_Surface     *load_image(char *str)
{
  SDL_Surface   *loading;

  loading = NULL;
  loading = IMG_Load(str);
  if (loading == NULL)
    {
      printf("Can't load the surface : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  return (loading);
}

int		init_sdl(t_graph *graph)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF) == -1)
    {
      printf("Can't init SDL: %s\n", SDL_GetError());
      return (-1);
    }
  graph->screen = SDL_SetVideoMode(graph->x, graph->y, 16,
				   SDL_HWSURFACE | SDL_FULLSCREEN);
  SDL_WM_SetCaption("Epikong", NULL);
  if (graph->screen == NULL)
    {
      printf("Can't set video mode: %s\n", SDL_GetError());
      return (-1);
    }
  setTexture(&graph);
  return (0);
}

void		setTexture(t_graph **graph)
{
  (*graph)->image = NULL;
  (*graph)->texture[EBLANK] = NULL;
  (*graph)->texture[EWALL] = load_image("images/Wall.png");
  (*graph)->texture[ELADDER] = load_image("images/Ladder.png");
  (*graph)->texture[EMONSTER] = load_image("images/Monster.png");
  (*graph)->texture[EEXIT] = load_image("images/Exit.png");
  (*graph)->left = load_image("images/Mario2.png");
  (*graph)->right = load_image("images/Mario.png");
  (*graph)->texture[EENTRY] = (*graph)->left;
  (*graph)->texture[EKEY] = load_image("images/Key.png");
}

void		apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *dest)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  if (SDL_BlitSurface(source, NULL, dest, &offset) != 0)
    {
      printf("Can't Blit the surface : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
}

void		free_surface(t_graph *graph)
{
  SDL_FreeSurface(graph->texture[EWALL]);
  SDL_FreeSurface(graph->texture[ELADDER]);
  SDL_FreeSurface(graph->texture[EMONSTER]);
  SDL_FreeSurface(graph->texture[EEXIT]);
  SDL_FreeSurface(graph->texture[EENTRY]);
  SDL_FreeSurface(graph->texture[EKEY]);
  SDL_FreeSurface(graph->image);
}
