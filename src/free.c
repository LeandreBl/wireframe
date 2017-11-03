/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** free structs
*/

#include "wireframe.h"

#include "my.h"

void		free_dots(frame_t *frame)
{
  int		i;

  i = 0;
  while (i < frame->size)
  {
    sfree(&frame->dots[i]);
    ++i;
  }
  sfree(&frame->dots);
}

void		free_frame(frame_t *frame)
{
  int           i;

  i = 0;
  free_dots(frame);
  while (i < frame->size)
  {
    sfree(&frame->lines[i].line);
    sfree(&frame->lines[i]);
    ++i;
  }
  sfree(&frame->lines);
}
