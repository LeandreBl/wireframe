/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** parse char ** into line_s *
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

static int	parse_line(const char *str, line_t *line)
{
  char		**parsed;
  int		i;

  i = 0;
  parsed = my_str_to_wordtab(str, SEP_CHAR);
  if (parsed == NULL)
    return (-1);
  line->size = tablen(parsed);
  line->line = my_calloc(sizeof(int) * line->size);
  if (line->line == NULL)
  {
    free_tab(&parsed);
    return (-1);
  }
  while (i < line->size)
  {
    line->line[i] = my_getnbr(parsed[i]);
    ++i;
  }
  free_tab(&parsed);
  return (0);
}

int		parse_file(char **file, frame_t *frame)
{
  int		i;

  frame->size = tablen(file);
  frame->lines = my_calloc(sizeof(line_t) * frame->size);
  if (frame->lines == NULL)
    return (-1);
  i = 0;
  while (i < frame->size)
  {
    if (parse_line(file[i], &frame->lines[i]) == -1)
    {
      sfree(&frame->lines);
      return (-1);
    }
    ++i;
  }
  return (0);
}
