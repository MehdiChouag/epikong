/*
** surface.h for surface.h in /home/chouag_m/rendu/T2Rush1
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Sat Mar  8 14:52:43 2014 Mehdi Chouag
** Last update Sun Mar  9 18:07:58 2014 Mehdi Chouag
*/

#ifndef SURFACE_H_
# define SURFACE_H_

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h> 
# include <SDL/SDL_rotozoom.h> 
# include "epikong.h"

typedef struct	s_graph
{
  SDL_Surface	*texture[NBC];
  SDL_Surface	*right;
  SDL_Surface	*left;
  SDL_Surface	*screen;
  SDL_Surface	*image;
  int		x;
  int		y;
  int		**map;
}		t_graph;

typedef struct	s_menu
{
  SDL_Surface	*fond;
  SDL_Surface	*screen;
  int		i;
  SDL_Event	event;
}		t_menu;

typedef struct  s_font
{
  TTF_Font	*map;
  SDL_Surface	*message[6];
  int		selected;
  char		*name[6];
  SDL_Color	red;
  SDL_Color	whi;
}               t_font;

SDL_Surface	*load_image(char *str);
int		init_sdl(t_graph *graph);
void		setTexture(t_graph **graph);
void		apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *dest);
void		free_surface(t_graph *graph);
void		refresh(t_map *imap, t_graph *graph);
void		aff_map(t_map *imap, t_graph *graph);
void		aff_dyn(t_map *imap, t_graph *graph);
void		apply_fond(t_graph *graph);
void		mainLoop(t_graph *graph, t_map *imap);
void		print_menu(t_font *font, t_menu *menu);
void		set_menu(t_font *font, t_menu *menu);
int		init_menu(t_menu *menu);
void		catch_key(Uint8 *key, t_font *font, t_menu *menu, int *c);
void		modif(t_font *font, t_menu *menu);
void		launch_map(Uint8 *key, t_font *font, t_menu *menu, int *c);
int		launch_game(char *file, int *i);
void		font_free(t_menu *menu, t_font *font);
void		move(int key, t_map *imap, t_graph *graph);
int		game(void);

#endif /* !SURFACE_H_ */
