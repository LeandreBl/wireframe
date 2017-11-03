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
      ++j;
    }
    ++i;
  }
}
static void	init_frame_settings(frame_t *frame)
{
  frame->angle = 60;
  frame->zoom = 10;
  frame->camera.y = frame->lines[frame->size / 2].size * frame->zoom / 2;
  frame->camera.x = frame->size * frame->zoom / 2 + frame->camera.y;
  frame->dots = NULL;
  frame->speed = 1;
  frame->disp_view = PARA_PROJ;
}

int		display_wireframe(t_window *window, frame_t *frame)
{
  init_frame_settings(frame);
  if (fill_3d_coordinates(frame) == -1)
    return (-1);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    clear_color(window, sfBlack);
    key_shortcuts(frame);
    display_cols(window, frame);
    display_lines(window, frame);
    close_win(window);
    window_refresh(window);
  }
  return (0);
}
