/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** compute 3D -> 2D
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static int	allocate_wires(frame_t *frame)
{
  int		i;

  i = 0;
  frame->dots = my_calloc(sizeof(sfVector2f *) * frame->size);
  if (frame->dots == NULL)
    return (-1);
  while (i < frame->size)
  {
    frame->dots[i] = my_calloc(sizeof(sfVector2f) * frame->lines[i].size);
    if (frame->dots[i] == NULL)
      return (-1);
    ++i;
  }
  return (0);
}

static void	set_coordinates(frame_t *frame)
{
  sfVector3f	proj;
  int		x;
  int		y;

  y = 0;
  while (y < frame->size)
  {
    x = 0;
    while (x < frame->lines[y].size)
    {
      proj = xyz_vector(x, y, frame->lines[y].line[x]);
      if (frame->disp_view == PARA_PROJ)
	frame->dots[y][x] = my_para_proj(proj, frame->angle);
      if (frame->disp_view == ISO_PROJ)
	frame->dots[y][x] = my_iso_proj(proj);
      ++x;
    }
    y++;
  }
}

int		fill_3d_coordinates(frame_t *frame)
{
  if (frame->dots == NULL && allocate_wires(frame) == -1)
  {
    mdprintf(2, "%sError : Could not allocate memory%s\n", BOLDRED, RESET);
    return (-1);
  }
  set_coordinates(frame);
  return (0);
}
