/*
** tekpixel.c for tekpixel in /home/tchikl_h/rendu/gfx_fdf1
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Nov 20 22:28:19 2015 Hervé TCHIKLADZE
** Last update Sat Apr 16 15:53:48 2016 Hervé TCHIKLADZE
*/

#include "lem_in.h"

void    tekpixel(t_bunny_pixelarray *pix, \
		 t_bunny_position pos, unsigned int color)
{
  t_color       *map;
  int           start;

  start = pos.y + pix->clipable.buffer.width * pos.x;
  map = (t_color*)pix->pixels;
  if (pos.y < pix->clipable.buffer.width && pos.y > 0 && \
      pos.x < pix->clipable.buffer.height && pos.x > 0)
  map[start].full = color;
}
