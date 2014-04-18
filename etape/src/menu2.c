/*
** menu2.c for menu2.c in /home/chouag_m/rendu/T2Rush1/etape_2/src
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Sun Mar  9 16:16:50 2014 Mehdi Chouag
** Last update Sun Mar  9 17:53:41 2014 Mehdi Chouag
*/

#include "surface.h"

void    modif(t_font *font, t_menu *menu)
{
  SDL_FillRect(menu->screen, NULL, 0x000000);
  apply_surface(0, 0, menu->fond, menu->screen);
  print_menu(font, menu);
  SDL_Flip(menu->screen);
}

void	launch_map(Uint8 *key, t_font *font, t_menu *menu, int *c)
{
  int	i;

  i = font->selected;
  if (key[SDLK_RETURN] && (i > 0 && i < 5))
    font_free(menu, font);
  if (key[SDLK_RETURN] && i == 0)
    *c = launch_game("maps/st1.map", c);
  else if (key[SDLK_RETURN] && i == 1)
    *c = launch_game("maps/st2.map", c);
  else if (key[SDLK_RETURN] && i == 2)
    *c = launch_game("maps/st3.map", c);
  else if (key[SDLK_RETURN] && i == 3)
    *c = launch_game("maps/st4.map", c);
  else if (key[SDLK_RETURN] && i == 4)
    *c = launch_game("maps/st5.map", c);
}

void	font_free(t_menu *menu, t_font *font)
{
  int	i;

  i = -1;
  while (++i < 5)
    SDL_FreeSurface(font->message[i]);
  SDL_FreeSurface(menu->fond);
  SDL_FreeSurface(menu->screen);
  TTF_CloseFont(font->map);
  TTF_Quit();
}
