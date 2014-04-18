/*
** test.c for  in /home/brunne_r/Public/sdl_test
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Fri Mar  7 20:46:33 2014 brunne-r
** Last update Sat Mar 15 15:42:40 2014 Mehdi Chouag
*/

#include "epikong.h"
#include "surface.h"

int		getIntMap(char *f, t_map *imap)
{
  char		**map;

  map = getMap(f);
  if (map)
    {
      imap->map = transformMap(map, &(imap->width));
      if (imap->map)
	{
	  imap->height = 0;
	  while (imap->map[(imap->height)++]);
	  freeMap(map);
	  initiMap(imap);
	  if (imap->monsters == NULL)
	    return (-1);
	}
      else
	return (-1);
    }
  else
    return (-1);
  return (1);
}

int		launch_game(char *file, int *i)
{
  t_map		imap;
  t_graph	graph;

  *i = 1;
  if (getIntMap(file, &imap) > 0)
    {
      graph.x = imap.width * BLOCK;
      graph.y = (imap.height - 1) * BLOCK;
      if (graph.x <= 1920 && graph.y <= 1080)
        {
          if (init_sdl(&graph) == 0)
            mainLoop(&graph, &imap);
	  free_surface(&graph);
        }
      else
        fprintf(stderr, "map is too big\n");
      freeiMap(&imap);
      SDL_Quit();
    }
  return (0);
}

Uint8		*minit(t_menu *m)
{
  m->i = 1;
  return SDL_GetKeyState(NULL);
}

int		game(void)
{
  t_menu	menu;
  t_font	font;
  Uint8		*key;

  key = minit(&menu);
  if (init_menu(&menu) == 0)
    {
      apply_surface(0, 0, menu.fond, menu.screen);
      set_menu(&font, &menu);
      if (SDL_Flip(menu.screen) == -1)
        {
          fprintf(stderr, "Can't flip the screen\n");
          return (EXIT_FAILURE);
        }
      while (menu.i)
        while (SDL_PollEvent(&menu.event))
          {
            if (menu.event.type == SDL_QUIT || key[SDLK_ESCAPE])
              menu.i = 0;
            catch_key(key, &font, &menu, &menu.i);
            launch_map(key, &font, &menu, &menu.i);
          }
    }
  SDL_Quit();
  return (EXIT_SUCCESS);
}

int		main(void)
{
  return (game());
}
