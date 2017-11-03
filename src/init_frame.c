/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** init frames settings
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

void            init_frame_settings(frame_t *frame)
{
  frame->angle = 60;
  frame->zoom = 10;
  frame->camera.y = frame->lines[frame->size / 2].size / 2 - 200;
  frame->camera.x = 680 - frame->size / 2;
  frame->dots = NULL;
  frame->speed = 1;
  frame->disp_view = ISO_PROJ;
}

static void	next_frame(frame_t *frames,
			   char **file, char *filename, int *i)
{
  init_frame_settings(&frames[*i]);
  fill_3d_coordinates(&frames[*i]);
  mprintf("[%sOK%s]\n", BOLDYELLOW, RESET);
  free_tab(&file);
  sfree(&filename);
  ++*i;
}

static int	fill_frames(frame_t *frames, folder_t *folder)
{
  int		i;
  char		**file;
  char		*filename;

  i = 0;
  while (i < folder->size)
  {
    filename = catalloc("%s/%s", folder->folder, folder->filenames[i]);
    if (filename == NULL)
      return (-1);
    mprintf("\t> %s%s : %s", BOLDBLUE, filename, RESET);
    file = load_file(filename);
    if (file == NULL)
    {
      mdprintf(2, "[%sKO%s]\n", BOLDRED, RESET);
      return (-1);
    }
    if (parse_file(file, &frames[i]) == -1)
    {
      mdprintf(2, "[%sKO%s]\n", BOLDRED, RESET);
      return (-1);
    }
    next_frame(frames, file, filename, &i);
  }
  return (0);
}

int		create_frames(frame_t **frames, folder_t *folder)
{
  mprintf("[%sOpening %s folder%s]\n", BOLDGREEN, folder->folder, RESET);
  folder->filenames = dir_filenames(folder->folder, 1);
  if (folder->filenames == NULL)
  {
    mdprintf(2, "%sError : Could not open %s%s\n", BOLDRED,
	     folder->folder, RESET);
    return (-1);
  }
  mprintf("[%sGenerating frames%s]\n", BOLDGREEN, RESET);
  folder->size = tablen(folder->filenames);
  *frames = my_calloc(sizeof(frame_t) * folder->size);
  if (*frames == NULL)
    return (-1);
  mprintf("[%sFilling frames :%s]\n", BOLDGREEN, RESET);
  if (fill_frames(*frames, folder) == -1)
    return (-1);
  return (0);
}
