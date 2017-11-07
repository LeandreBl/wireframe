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
  window_t	*window;
  folder_t	folder;
  frame_t	*frames;

  if (ac != 2)
    return (mdprintf(2, "%sUsage\n\t./wireframe file.wf\n%s",
		     BOLDGREEN, RESET));
  window = init_window(720, 16.0 / 9.0, NULL, 0);
  if (window == NULL)
    return (-1);
  window->font = my_strdup(FONT);
  folder.folder = av[1];
  if (create_frames(&frames, &folder) == -1)
  {
    mdprintf(2, "%sError : Could not create frames%s\n", BOLDRED, RESET);
    free_tab(&folder.filenames);
    free_window(window);
    return (-1);
  }
  menu(window, frames, &folder);
  free_frames(frames, folder.size);
  free_tab(&folder.filenames);
  free_window(window);
  return (0);
}
