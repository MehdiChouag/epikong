/*
** map.c for  in /home/brunne_r/Public/sdl_test
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Fri Mar  7 20:48:36 2014 brunne-r
** Last update Sun Mar  9 18:01:19 2014 brunne-r
*/

#include "epikong.h"

int		lenMap(FILE *f)
{
  int		x;
  size_t	n;
  char		*l;

  x = 0;
  l = NULL;
  while (getline(&l, &n, f) > 0)
    {
      x++;
      free(l);
      l = NULL;
    }
  rewind(f);
  return x;
}

char		**recupMap(FILE *f)
{
  int		x;
  char		**map;
  char		*l;
  size_t	n;

  x = lenMap(f);
  map = malloc(sizeof(char*) * (x + 1));
  if (map)
    {
      l = NULL;
      x = 0;
      while (getline(&l, &n, f) > 0)
	{
	  l[strlen(l) - 1] = 0;
	  map[x++] = l;
	  l = NULL;
	}
      map[x] = NULL;
      return (map);
    }
  else
    return (NULL);
}

void	freeMap(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    {
      free(map[i]);
      ++i;
    }
  free(map);
}

char	**getMap(char *file)
{
  char	**map;
  FILE	*f;

  map = NULL;
  f = fopen(file, "r");
  if (f != NULL)
    {
      map = recupMap(f);
      if (checkMap(map) < 0)
	{
	  fprintf(stderr, "%s : is not a valid map\n", file);
	  return (NULL);
	}
    }
  else
    fprintf(stderr, "%s : cannot open file\n", file);
  return (map);
}
