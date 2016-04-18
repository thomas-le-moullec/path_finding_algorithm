/*
** noise_color.c for noise_color in /home/tchikl_h/rendu/B2/CPE/CPE_2015_Lemin/bonus
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Sat Apr 16 14:40:13 2016 Hervé TCHIKLADZE
** Last update Sat Apr 16 14:41:16 2016 Hervé TCHIKLADZE
*/

#include "lem_in.h"

void            noise_color_full(t_bunny_pixelarray  *pix)
{
  t_color       *colpix;
  int           i;

  i = 0;
  colpix = (t_color*)pix->pixels;
  while (i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      colpix[i].full = 0;
      i++;
    }
}
