/*
** tekline.c for tekline in /home/tchikl_h/rendu/gfx_fdf1
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Nov 20 22:28:45 2015 Hervé TCHIKLADZE
** Last update Mon Apr 18 16:36:44 2016 Hervé TCHIKLADZE
*/

#include "lem_in.h"

t_bunny_position        *swap(t_bunny_position *pos)
{
  int   swap;

  swap = pos[0].x;
  pos[0].x = pos[1].x;
  pos[1].x = swap;
  swap = pos[0].y;
  pos[0].y = pos[1].y;
  pos[1].y = swap;
  return (pos);
}

void    tekline_swap(t_bunny_pixelarray *pix, \
		     t_bunny_position *pos, unsigned int color)
{
  int   i;
  float coef;
  float rest;

  pos = swap(pos);
  i = pos[0].x;
  coef = ((float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x));
  while (i < pos[1].x)
    {
      pos[0].x = i;
      pos[0].y = (i - pos[1].x) * coef + pos[1].y;
      tekcircle(pix, pos[0], color, 7);
      rest = coef;
      if (rest < 0)
        rest = -rest;
      while (rest-- > 0)
        {
          pos[0].y = pos[0].y - 1;
          tekcircle(pix, pos[0], color, 7);
        }
      i++;
    }
}

void    tekline_vertical(t_bunny_pixelarray *pix, \
			 t_bunny_position *pos, unsigned int color)
{
  int   i;

  i = pos[0].y;
  if ((pos[1].x - pos[0].x) == 0)
    {
      if (pos[0].y > pos[1].y)
        while (i > pos[1].y)
          {
            pos[0].y = pos[0].y - 1;
            tekcircle(pix, pos[0], color, 7);
            i--;
          }
      if (pos[0].y < pos[1].y)
        while (i < pos[1].y)
          {
            pos[0].y = pos[0].y + 1;
            tekcircle(pix, pos[0], color, 7);
            i++;
          }
    }
}

int	swap_pos(int **save, t_bunny_position **pos)
{
  if ((*save) == NULL)
    {
      if (!((*save) = malloc(sizeof(*(*save)) * 4)))
	return (ERROR);
      (*save)[0] = (*pos)[0].x;
      (*save)[1] = (*pos)[0].y;
      (*save)[2] = (*pos)[1].x;
      (*save)[3] = (*pos)[1].y;
      return (SUCCESS);
    }
  else
    {
      (*pos)[0].x = (*save)[0];
      (*pos)[0].y = (*save)[1];
      (*pos)[1].x = (*save)[2];
      (*pos)[1].y = (*save)[3];
    }
  return (SUCCESS);
}

int    tekline(t_bunny_pixelarray *pix, \
	       t_bunny_position *pos, t_data *data, unsigned int color)
{
  int	*save;
  int   i;
  float coef;
  float rest;

  data = data;
  save = NULL;
  swap_pos(&save, &pos);
  i = pos[0].x;
  coef = ((float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x));
  tekline_vertical(pix, pos, color);
  while (i < pos[1].x)
    {
      pos[0].x = i;
      pos[0].y = (i - pos[1].x) * coef + pos[1].y;
      tekcircle(pix, pos[0], color, 7);
      rest = coef;
      if (rest < 0)
        rest = -rest;
      while (rest-- > 0)
        {
          pos[0].y = pos[0].y - 1;
          tekcircle(pix, pos[0], color, 7);
        }
      i++;
    }
  tekline_swap(pix, pos, color);
  swap_pos(&save, &pos);
  return (SUCCESS);
}
