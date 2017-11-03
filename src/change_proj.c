/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** change proj
*/

#include "wireframe.h"

void		change_proj(frame_t *frame)
{
  float		coef;

  if (key_released(sfKeyX))
    frame->disp_view = (frame->disp_view + 1) % NB_PROJ;
  coef = frame->speed * frame->zoom * frame->size;
  if (frame->disp_view == PARA_PROJ)
  {
    frame->camera.x += coef;
    frame->camera.y += coef;
  }
  else if (frame->disp_view == ISO_PROJ)
  {
    frame->camera.x -= coef;
    frame->camera.y -= coef;
  }
}
