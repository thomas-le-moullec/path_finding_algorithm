/*
** tekcircle.c for tekcircle in /home/tchikl_h/rendu/gfx_wolf3d/lib/my
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Dec 25 19:32:23 2015 Hervé TCHIKLADZE
** Last update Sat Apr 16 15:11:14 2016 Hervé TCHIKLADZE
*/

#include "lem_in.h"

void                    tekcircle(t_bunny_pixelarray *pix, \
				  t_bunny_position pos, unsigned int color,  int radius)
{
  int                   x;
  int                   width;
  int                   height;

  x = 0;
  width = pos.x;
  height = pos.y;
  while (radius > 0)
    {
      while (x < 3600)
        {
          pos.x = height + radius * cos(x);
          pos.y = width + radius * sin(x);
	  if (pos.x >= 0 && pos.x <= 720 && pos.y >= 0 && pos.y <= 1080)
	    tekpixel(pix, pos, color);
          x++;
        }
      x = 0;
      radius--;
    }
}
