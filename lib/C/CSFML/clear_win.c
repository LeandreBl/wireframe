/*
** clear_win.c for clear_win in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:04:57 2017 Léandre Blanchard
** Last update Fri Nov  3 01:58:14 2017 Léandre Blanchard
*/

#include "csfml.h"
/*
** clear the t_window current's sprites
*/
void            window_clear(t_window *window)
{
  sfRenderWindow_clear(window->window, sfWhite);
}
/*
** refresh the window by displaying the sprites,
** and the pixels contained in window->pixels
*/
void            window_refresh(t_window *window)
{
  sfTexture_updateFromPixels(window->texture, window->pixels,
			     window->width, window->height, 0, 0);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
  sfRenderWindow_display(window->window);
}

/*
** Fill all the pixel of window->pixels with color
*/
void		clear_color(t_window *window, sfColor color)
{
  int		x;
  int		y;

  y = 0;
  while (y < window->height)
  {
    x = 0;
    while (x < window->width)
    {
      my_put_pixel(window, x, y, color);
      ++x;
    }
    y++;
  }
}

/*
** fill all the bytes of the pixel array in t_window
** with blank
*/
void		clear_white(t_window *window)
{
  int		i;

  i = 0;
  while (i != window->height * 4 * window->width)
    window->pixels[i++] = 255;
}
