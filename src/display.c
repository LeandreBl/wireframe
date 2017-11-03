/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** display
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

static void	display_cols(t_window *window, frame_t *frame)
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
      my_draw_line(window, frame->dots[i][j], frame->dots[i + 1][j], sfWhite);
      if (frame->dots[i][j].y > window->height)
	break;
      if (frame->dots[i + 1][j].y < 0)
	++i;
      ++i;
    }
    ++j;
  }
}

static void	display_lines(t_window *window, frame_t *frame)
{
  int		i;
  int		j;

  i = 0;
  while (i < frame->size)
  {
    j = 0;
    while (j < frame->lines[i].size - 1)
    {
      my_draw_line(window, frame->dots[i][j], frame->dots[i][j + 1], sfWhite);
      if (frame->dots[i][j].x > window->width)
	break;
      if (frame->dots[i][j + 1].x < 0)
	++j;
      ++j;
    }
    ++i;
  }
}

int		display_wireframe(t_window *window, frame_t *frame)
{
  while (sfRenderWindow_isOpen(window->window)
	 && !KP(sfKeyEscape))
  {
    window_clear(window);
    clear_color(window, sfBlack);
    key_shortcuts(frame);
    display_cols(window, frame);
    display_lines(window, frame);
    window_refresh(window);
  }
  key_released(sfKeyEscape);
  return (0);
}
