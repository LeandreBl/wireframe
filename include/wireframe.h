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

# define SHORTCUTS	(7)

struct			fct_s
{
  int			key;
  void			(*fction)(struct frame_s *frame);
};

typedef struct line_s line_t;
typedef struct frame_s frame_t;
typedef struct fct_s fct_t;

void		free_dots(frame_t *frame);
void		free_frame(frame_t *frame);
int		parse_file(char **file, frame_t *frame);
sfVector2f	my_para_proj(sfVector3f pos3d, float angle);
sfVector2f	my_iso_proj(sfVector3f pos3d);
int		fill_3d_coordinates(frame_t *frame);
int		display_wireframe(t_window *window, frame_t *frame);
void		key_shortcuts(frame_t *frame);

/* Function pointers */
void		up_key(frame_t *frame);
void            down_key(frame_t *frame);
void            left_key(frame_t *frame);
void            right_key(frame_t *frame);
void		page_up(frame_t *frame);
void		page_down(frame_t *frame);
void		change_proj(frame_t *frame);

#endif /* !WIREFRAME_H_ */
