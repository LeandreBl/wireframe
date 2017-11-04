/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** display
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

sfVector2f		get_pos(int i, int j, frame_t *frame)
{
  sfVector2f		pos;

  pos = frame->dots[i][j];
  pos.x = pos.x * frame->zoom + frame->camera.x;
  pos.y = pos.y * frame->zoom + frame->camera.y;
  return (pos);
}

static void	display_cols(t_window *window, frame_t *frame)
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
      my_draw_line(window, from, to, sfWhite);
      if (from.y > window->height)
	break;
      if (to.y < 0)
	++i;
      ++i;
    }
    ++j;;
  }
}

static void	display_lines(t_window *window, frame_t *frame)
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
      my_draw_line(window, from, to, sfWhite);
      if (from.x > window->width)
	break;
      if (to.x < 0)
	++j;
      ++j;
    }
    ++i;
  }
}

int		display_wireframe(t_window *window, frame_t *frame)
{
  sfColor	color;
  char		*hud;
  sfVector2f	pos;

  color = sfColor_fromRGB(30, 30, 30);
  pos = xy_vectorf(20, 10);
  while (sfRenderWindow_isOpen(window->window)
	 && !KP(sfKeyEscape))
  {
    window_clear(window);
    clear_color(window, color);
    key_shortcuts(frame);
    display_cols(window, frame);
    display_lines(window, frame);
    window_update(window);
    hud = catalloc("Angle : %f deg.\nSpeed : %f\nCamera : (%f, %f)\nZoom : %fx\nMap : [%d x %d]",
		   frame->angle, frame->speed, frame->camera.x,
		   frame->camera.y, frame->zoom / DEFAULT_ZOOM,
		   frame->size, frame->lines[0].size);
    put_word(hud, pos, window, sfYellow);
    sfree(&hud);
    sfRenderWindow_display(window->window);
  }
  key_released(sfKeyEscape);
  return (0);
}
