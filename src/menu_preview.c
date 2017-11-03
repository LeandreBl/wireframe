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

  j = 0;
  i = 0;
  while (j < frame->lines[i].size)
  {
    i = 0;
    while (i < frame->size - 1)
    {
      menu_line(preview, frame->dots[i][j], frame->dots[i + 1][j], sfWhite);
      if (frame->dots[i][j].y > preview->height)
	break;
      if (frame->dots[i + 1][j].y < 0)
	++i;
      ++i;
    }
    ++j;
  }
}

static void	display_lines(preview_t *preview, frame_t *frame)
{
  int		i;
  int		j;

  i = 0;
  while (i < frame->size)
  {
    j = 0;
    while (j < frame->lines[i].size - 1)
    {
      menu_line(preview, frame->dots[i][j], frame->dots[i][j + 1], sfWhite);
      if (frame->dots[i][j].x > preview->width)
	break;
      if (frame->dots[i][j + 1].x < 0)
	++j;
      ++j;
    }
    ++i;
  }
}

int		display_preview(t_window *window, preview_t *preview,
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
