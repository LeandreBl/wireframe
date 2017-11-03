/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** arrow key
*/

#include "wireframe.h"

# define SHIFT	(frame->speed * frame->zoom)

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
