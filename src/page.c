/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** page up / down
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

void		page_up(frame_t *frame)
{
  frame->zoom *= 1.02;
  frame->camera.y -= frame->zoom;
  frame->camera.x -= frame->zoom;
}

void		page_down(frame_t *frame)
{
  if (frame->zoom > 0.2)
  {
    frame->zoom /= 1.02;
    frame->camera.y += frame->zoom;
    frame->camera.x += frame->zoom;
  }
}
