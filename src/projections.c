/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** projections
*/

#include "wireframe.h"

sfVector2f	my_para_proj(sfVector3f pos3d, float angle)
{
  sfVector2f	point;

  angle = angle * M_PI / 180;
  angle = angle + M_PI / 2;
  point.x = pos3d.x + pos3d.y * cos(angle);
  point.y = (-pos3d.z) + pos3d.y * sin(angle);
  return (point);
}

sfVector2f	my_iso_proj(sfVector3f pos3d)
{
  int		angle;
  sfVector2f	point;

  angle = 30 * M_PI / 180;
  point.x = (cos(angle) * (pos3d.x - pos3d.y));
  point.y = 1 / sqrt(6) * (pos3d.x + pos3d.y) - sqrt_2_3 * pos3d.z;
  return (point);
}

