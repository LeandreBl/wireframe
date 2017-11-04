/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** arrow key
*/

#include "wireframe.h"

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
  frame->camera.y += frame->speed;
}

void		down_key(frame_t *frame)
{
  frame->camera.y -= frame->speed;
}

void		left_key(frame_t *frame)
{
  frame->camera.x += frame->speed;
}

void		right_key(frame_t *frame)
{
  frame->camera.x -= frame->speed;
}
