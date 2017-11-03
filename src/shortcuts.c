/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** key shortcuts
*/

#include "wireframe.h"

static void	__add__(int key, fct_t *index,
			   void (*fction)(frame_t *frame))
{
  index->key = key;
  index->fction = fction;
}

static void	init_tab(fct_t tab[])
{
  __add__(sfKeyUp, &tab[0], up_key);
  __add__(sfKeyDown, &tab[1], down_key);
  __add__(sfKeyLeft, &tab[2], left_key);
  __add__(sfKeyRight, &tab[3], right_key);
  __add__(sfKeyPageUp, &tab[4], page_up);
  __add__(sfKeyPageDown, &tab[5], page_down);
  __add__(sfKeyX, &tab[6], change_proj);
}

void		key_shortcuts(frame_t *frame)
{
  static int	calls;
  static fct_t	tab[SHORTCUTS];
  int		i;

  if (calls == 0)
  {
    init_tab(tab);
    ++calls;
  }

  i = 0;
  while (i < SHORTCUTS)
  {
    if (KP(tab[i].key))
      tab[i].fction(frame);
    ++i;
  }
  fill_3d_coordinates(frame);
}
