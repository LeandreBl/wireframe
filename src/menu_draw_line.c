/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** menu preview
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

int		menu_pixel(preview_t *preview, int x, int y, sfColor color)
{
  if (x < 0 || y < 0)
    return (-1);
  if (x >= preview->width || y >= preview->height)
    return (-1);
  preview->pixels[(preview->width * y + x) * 4 + 0] = color.r;
  preview->pixels[(preview->width * y + x) * 4 + 1] = color.g;
  preview->pixels[(preview->width * y + x) * 4 + 2] = color.b;
  preview->pixels[(preview->width * y + x) * 4 + 3] = color.a;
  return (0);
}

static void	swaper(sfVector2f *from, sfVector2f *to)
{
  sfVector2f	swp;

  if (from->x > to->x)
  {
    swp = *from;
    *from = *to;
    *to = swp;
  }
}

void		menu_line(preview_t *preview, sfVector2f from,
			     sfVector2f to, sfColor color)
{
  sfVector2f	xy;
  float		a;
  float		b;

  swaper(&from, &to);
  a = (to.y - from.y) / (to.x - from.x);
  b = from.y - (a * from.x);
  xy.x = from.x;
  while (xy.x < to.x)
  {
    xy.y = a * xy.x + b;
    menu_pixel(preview, (int)xy.x, (int)xy.y, color);
    xy.x += 0.2;
  }
  while (xy.x < to.x && to.y == from.y)
    menu_pixel(preview, (int)xy.x, (int)xy.y++, color);
}
