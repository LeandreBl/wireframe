/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** main
*/

#include "wireframe.h"

#include "colors.h"
#include "my.h"
#include "defines.h"

int		main(int ac, char **av)
{
  t_window	*window;
  char		**file;
  frame_t	frame;

  if (ac != 2)
    return (mdprintf(2, "%sUsage\n\t./wireframe file.wf\n%s", BOLDGREEN, RESET));
  window = init_window(720, 16.0 / 9.0, NULL, 0);
  if (window == NULL)
    return (-1);
  file = load_file(av[1]);
  if (file == NULL)
  {
    mdprintf(2, "%sError : Could not open %s\n%s", BOLDRED, av[1], RESET);
    return (-1);
  }
  if (parse_file(file, &frame) == -1)
  {
    mdprintf(2, "%sError : Could not parse %s%s\n", BOLDRED, av[1], RESET);
    free_window(window);
    free_tab(&file);
  }
  display_wireframe(window, &frame);
  free_frame(&frame);
  free_window(window);
  free_tab(&file);
  return (0);
}
