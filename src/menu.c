/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** menu
*/

#include "wireframe.h"

#include "my.h"
#include "defines.h"

static void	display_names(window_t *window, folder_t *folder, int cur)
{
  int		i;
  sfVector2f	pos;

  i = 0;
  while (i < folder->size)
  {
    pos.x = 50;
    pos.y = 50 + (window->height - 100) / folder->size * i;
    if (i != cur)
      put_word(folder->filenames[i], pos, window, sfWhite);
    else
      put_word(folder->filenames[i], pos, window, sfYellow);
    ++i;
  }
}

static int	build_preview(preview_t *preview, sprite_t **cursor,
			      sprite_t **background, window_t *window)
{
  preview->width = window->width;
  preview->height = window->height;
  preview->pixels = pixels_buffer(preview->width, preview->height);
  preview->sprite.texture = sfTexture_create(preview->width, preview->height);
  preview->sprite.sprite = sfSprite_create();
  *cursor = create_sprite("sprites/cursor.png");
  *background = create_sprite("sprites/menu_background.png");
  if (*cursor == NULL || *background == NULL || preview->pixels == NULL
      || preview->sprite.sprite == NULL || preview->sprite.texture == NULL)
    return (-1);
  return (0);
}

static void	start_wireframe(window_t *window, frame_t *frame)
{
  if (key_released(sfKeyReturn))
  {
    display_wireframe(window, frame);
    clear_color(window, sfColor_fromRGBA(0, 0, 0, 0));
  }
}

int		menu(window_t *window, frame_t *frames, folder_t *folder)
{
  int		cur;
  sfVector2f	position;
  sprite_t	*cursor;
  sprite_t	*background;
  preview_t	preview;

  if (build_preview(&preview, &cursor, &background, window) == -1)
    return (-1);
  cur = 0;
  while (sfRenderWindow_isOpen(window->window)
	 && !KP(sfKeyEscape))
  {
    window_clear(window);
    put_sprite(window, background, xy_vectorf(0, 0));
    move_menu_cursor(&cur, folder->size);
    position = xy_vectorf(40 + my_strlen(folder->filenames[cur]) * 15,
	       50 + (window->height - 100) / folder->size * cur + 17);
    display_names(window, folder, cur);
    put_sprite(window, cursor, position);
    start_wireframe(window, &frames[cur]);
    display_preview(window, &preview, &frames[cur]);
    window_refresh(window);
  }
  free_menu(&preview, background, cursor);
  return (0);
}
