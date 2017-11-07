/*
** EPITECH PROJECT, 2017
** wireframe
** File description:
** header
*/

#ifndef WIREFRAME_H_
# define WIREFRAME_H_

# define SEP_CHAR	(',')
# define sqrt_2_3	(0.81649658092)
# define NB_PROJ	(2)
# define PARA_PROJ	(0)
# define ISO_PROJ	(1)
# define DEFAULT_SPEED	(10)
# define DEFAULT_ZOOM	(10)
# define DEFAULT_ANGLE	(60)
# define FONT		("fonts/audims.ttf")

# include "csfml.h"

struct			line_s
{
  int			*line;
  int			size;
};

struct			frame_s
{
  struct line_s		*lines;
  int			size;
  sfVector2f		**dots;
  float			angle;
  float			zoom;
  sfVector2f		camera;
  float			speed;
  int			disp_view;
};

struct			folder_s
{
  const char		*folder;
  char			**filenames;
  int			size;
};

struct			preview_s
{
  int			width;
  int			height;
  sfUint8		*pixels;
  sprite_t		sprite;
};

# define SHORTCUTS	(8)

struct			fct_s
{
  int			key;
  void			(*fction)(struct frame_s *frame);
};

typedef struct preview_s preview_t;
typedef struct line_s line_t;
typedef struct frame_s frame_t;
typedef struct fct_s fct_t;
typedef struct folder_s folder_t;

int		create_frames(frame_t **frames, folder_t *folder);
void		init_frame_settings(frame_t *frame);
void		free_frames(frame_t *frame, int size);
int		parse_file(char **file, frame_t *frame);
sfVector2f	my_para_proj(sfVector3f pos3d, float angle);
sfVector2f	my_iso_proj(sfVector3f pos3d);
int		fill_3d_coordinates(frame_t *frame);
int		display_wireframe(window_t *window, frame_t *frame);
int		display_preview(window_t *window, preview_t *preview,
				frame_t *frame);
void		menu_line(preview_t *preview, sfVector2f from,
			  sfVector2f to, sfColor color);
int		menu(window_t *window, frame_t *frame, folder_t *folder);
void		key_shortcuts(frame_t *frame);
void		move_menu_cursor(int *cur, int max);
void		free_menu(preview_t *preview, sprite_t *background,
			  sprite_t *cursor);
sfVector2f	get_pos(int i, int j, frame_t *frame);

/* Function pointers */
void		up_key(frame_t *frame);
void            down_key(frame_t *frame);
void            left_key(frame_t *frame);
void            right_key(frame_t *frame);
void		page_up(frame_t *frame);
void		page_down(frame_t *frame);
void		change_proj(frame_t *frame);
void		change_angle(frame_t *frame);

#endif /* !WIREFRAME_H_ */
