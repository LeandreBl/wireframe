/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** display preview
*/

#include "wireframe.h"

static void	display_cols(preview_t *preview, frame_t *frame)
{
  int		i;
  int		j;
  sfVector2f	from;
  sfVector2f	to;

  j = 0;
  i = 0;
  while (j < frame->lines[i].size)
  {
    i = 0;
    while (i < frame->size - 1)
    {
      from = get_pos(i, j, frame);
      to = get_pos(i + 1, j, frame);
      menu_line(preview, from, to, sfWhite);
      if (from.y > preview->height)
	break;
      ++i;
    }
    ++j;
  }
}

static void	display_lines(preview_t *preview, frame_t *frame)
{
  int		i;
  int		j;
  sfVector2f	from;
  sfVector2f	to;

  i = 0;
  while (i < frame->size)
  {
    j = 0;
    while (j < frame->lines[i].size - 1)
    {
      from = get_pos(i, j, frame);
      to = get_pos(i, j + 1, frame);
      menu_line(preview, from, to, sfWhite);
      if (from.x > preview->width)
	break;
      ++j;
    }
    ++i;
  }
}

int		display_preview(window_t *window, preview_t *preview,
				frame_t *frame)
{
  display_cols(preview, frame);
  display_lines(preview, frame);
  sfTexture_updateFromPixels(preview->sprite.texture, preview->pixels,
			     preview->width, preview->height, 0, 0);
  sfSprite_setTexture(preview->sprite.sprite, preview->sprite.texture, sfTrue);
  zeros((char *)preview->pixels, preview->height * preview->width * 4);
  put_sprite_resize(window, &preview->sprite,
		    xy_vectorf(600, 200), xy_vectorf(0.5, 0.5));
  return (0);
}
