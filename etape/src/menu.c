/*
** menu.c for Menu in /home/chouag_m/rendu/T2Rush1/etape_2/src
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Sun Mar  9 13:51:53 2014 Mehdi Chouag
** Last update Fri Apr 18 13:57:15 2014 Mehdi Chouag
*/

#include "surface.h"

void	print_menu(t_font *font, t_menu *menu)
{
  int	i;
  int	pos;

  i = -1;
  pos = 200;
  while (++i < 6)
    {
      apply_surface(850, pos, font->message[i], menu->screen);
      pos += 80;
    }
}

void            set_menu(t_font *font, t_menu *menu)
{
  font->red.r = 255;
  font->red.g = 0;
  font->red.b = 0;
  font->whi.r = 0;
  font->whi.g = 0;
  font->whi.b = 0;
  font->name[0] = "Map 1";
  font->name[1] = "Map 2";
  font->name[2] = "Map 3";
  font->name[3] = "Map 4";
  font->name[4] = "Map 5";
  font->name[5] = "Exit";
  font->selected = 0;
  font->map = TTF_OpenFont("font/leadcoat.ttf", 80);
  font->message[0] = TTF_RenderText_Solid(font->map, "Map 1", font->red);
  font->message[1] = TTF_RenderText_Solid(font->map, "Map 2", font->whi);
  font->message[2] = TTF_RenderText_Solid(font->map, "Map 3", font->whi);
  font->message[3] = TTF_RenderText_Solid(font->map, "Map 4", font->whi);
  font->message[4] = TTF_RenderText_Solid(font->map, "Map 5", font->whi);
  font->message[5] = TTF_RenderText_Solid(font->map, "Exit", font->whi);
  print_menu(font, menu);
}

int	init_menu(t_menu *menu)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF) == -1)
    {
      printf("Can't init SDL: %s\n", SDL_GetError());
      return (-1);
    }
  menu->screen = SDL_SetVideoMode(1920, 1080,
				  16, SDL_HWSURFACE | SDL_FULLSCREEN);
  SDL_WM_SetCaption("Epikong", NULL);
  if (menu->screen == NULL)
    {
      printf("Can't set video mode: %s\n", SDL_GetError());
      return (-1);
    }
  TTF_Init();
  menu->fond = load_image("images/fond.jpg");
  return (0);
}

void	catch_key(Uint8 *key, t_font *font, t_menu *menu, int *c)
{
  int	i;

  i = font->selected;
  if (key[SDLK_DOWN] && i < 5)
    {
      font->message[i] = TTF_RenderText_Solid(font->map,
					      font->name[i], font->whi);
      font->message[i + 1] = TTF_RenderText_Solid(font->map,
						  font->name[i + 1], font->red);
      modif(font, menu);
      font->selected++;
    }
  if (key[SDLK_UP] && i > 0)
    {
      font->message[i] = TTF_RenderText_Solid(font->map,
					      font->name[i], font->whi);
      font->message[i - 1] = TTF_RenderText_Solid(font->map,
						  font->name[i - 1], font->red);
      modif(font, menu);
      font->selected--;
    }
  if (key[SDLK_RETURN] && i == 5)
    *c = 0;
}
