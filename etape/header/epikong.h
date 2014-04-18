/*
** epikong.h for  in /home/brunne_r/Public/sdl_test
** 
** Made by brunne-r
** Login   <brunne-r@epitech.net>
** 
** Started on  Fri Mar  7 20:45:38 2014 brunne-r
*/

#ifndef EPIKONG_H
# define EPIKONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h> 

# define	WALL	'w'
# define	LADDER	's'
# define	MONSTER	'm'
# define	EXIT	'o'
# define	ENTRY	'i'
# define	BLANK	'.'
# define	KEY	'k'
# define	NBC	7
# define	BLOCK	44

typedef	enum e_Elem
  {
    EBLANK = 0,
    EWALL,
    ELADDER,
    EMONSTER,
    EEXIT,
    EENTRY,
    EKEY
  } Elem;

typedef struct	s_movable
{
  int	x;
  int	y;
  Elem	type;
  int	flag;
}		t_movable;

typedef struct	s_map
{
  int		**map;
  int		width;
  int		height;
  t_movable	j;
  t_movable	*monsters;
  int		nbMonsters;
}		t_map;

char	**getMap(char *file);
int	checkMap(char **map);
void	freeMap(char **map);
void	freeiMap(t_map *imap);
void	affIntMap(int **map, int w);
int	**transformMap(char **map, int *w);
void	gravity(t_map *imap);
void	getPlayer(t_map *imap, int *x, int *y);
void	ladder_up(int x, int y, t_map *imap);
void	jump(int x, int y, t_map *imap);
void	isJump(void);
void	jumpmove(Uint8 *k, t_map *imap);
void	initiMap(t_map *imap);
void	monster(t_map *imap);

#endif /* !EPIKONG_H */
