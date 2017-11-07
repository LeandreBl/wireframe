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

void		free_frames(frame_t *frames, int size)
{
  int		i;

  i = 0;
  while (i < size)
  {
    free_frame(&frames[i]);
    ++i;
  }
  sfree(&frames);
}

void		free_menu(preview_t *preview,
			  sprite_t *background, sprite_t *cursor)
{
  free_sprite(cursor);
  free_sprite(background);
  sfree(&preview->pixels);
  sfSprite_destroy(preview->sprite.sprite);
  sfTexture_destroy(preview->sprite.texture);
}
