/*
** monster.c for  in /home/keller_l/rendu/T2Rush1/etape_2/src
** 
** Made by keller_l
** Login   <keller_l@epitech.net>
** 
** Started on  Sun Mar  9 13:48:52 2014 keller_l
** Last update Sun Mar  9 17:42:49 2014 brunne-r
*/

#include	"epikong.h"

void		moveMonster(t_map *imap, t_movable *m)
{
  if ((imap->map[m->x + 1][m->y + 1] == EWALL ||			\
       imap->map[m->x + 1][m->y + 1] == ELADDER) &&			\
      (imap->map[m->x][m->y + 1] == EBLANK ||				\
       imap->map[m->x][m->y + 1] == ELADDER) &&				\
      m->flag > 0 && !((m->y + 1) ==  imap->j.y && m->x == imap->j.x))
    m->y += 1;
  else if ((imap->map[m->x + 1][m->y - 1] == EWALL ||			\
       imap->map[m->x + 1][m->y - 1] == ELADDER) &&			\
      (imap->map[m->x][m->y - 1] == EBLANK ||				\
       imap->map[m->x][m->y - 1] == ELADDER ) &&			\
	   m->flag < 0 && !((m->y - 1) ==  imap->j.y && m->x == imap->j.x))
    m->y -= 1;
  else
    m->flag *= -1;
}

void		monster(t_map *imap)
{
  int		i;

  i = 0;
  while (i < imap->nbMonsters)
    {
      moveMonster(imap, &(imap->monsters[i]));
      i++;
    }
}
