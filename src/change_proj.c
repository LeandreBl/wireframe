/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** change proj
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

void		change_angle(frame_t *frame)
{
  if (frame->disp_view == PARA_PROJ)
    frame->angle += 1.5;
  if (frame->angle >= 360)
    frame->angle = 1;
}
void		change_proj(frame_t *frame)
{
  if (key_released(sfKeyX))
    frame->disp_view = (frame->disp_view + 1) % NB_PROJ;
}
