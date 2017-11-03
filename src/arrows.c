/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** arrow key
*/

#include "wireframe.h"

# define SHIFT	(frame->speed * frame->zoom)

void		move_menu_cursor(int *cur, int max)
{
  if (key_released(sfKeyUp))
    --*cur;
  else if (key_released(sfKeyDown))
    ++*cur;
  if (*cur < 0)
    *cur = max - 1;
  else if (*cur >= max)
    *cur = 0;
}

void		up_key(frame_t *frame)
{
  float		coef;

  coef = SHIFT;
  frame->camera.x += coef;
  frame->camera.y += coef;
}

void		down_key(frame_t *frame)
{
  float		coef;

  coef = SHIFT;
  frame->camera.y -= coef;
  frame->camera.x -= coef;
}

void		left_key(frame_t *frame)
{
  float		coef;

  coef = SHIFT;
  if (frame->disp_view == PARA_PROJ)
    frame->camera.x += coef;
  if (frame->disp_view == ISO_PROJ)
  {
    frame->camera.y -= coef / 2;
    frame->camera.x += coef / 2;
  }
}

void		right_key(frame_t *frame)
{
  float		coef;

  coef = SHIFT;
  if (frame->disp_view == PARA_PROJ)
    frame->camera.x -= coef;
  if (frame->disp_view == ISO_PROJ)
  {
    frame->camera.y += coef / 2;
    frame->camera.x -= coef / 2;
  }
}
