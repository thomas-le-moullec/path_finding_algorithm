/*
** graphic.c for graphic in /home/tchikl_h/rendu/B2/CPE/CPE_2015_Lemin/bonus/sources/graphic
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Sat Apr 16 11:25:12 2016 Hervé TCHIKLADZE
** Last update Wed Apr 20 11:18:30 2016 leo LE DIOURON
*/

#include "lem_in.h"

int			graphic(t_data *data)
{
  noise_color_full(data->graph->pix);
  if (draw_links(data) == ERROR)
    return (ERROR);
  bunny_blit(&data->graph->win->buffer, &data->graph->pix->clipable, NULL);
  bunny_blit(&data->graph->win->buffer, data->graph->pic, NULL);
  bunny_display(data->graph->win);
  return (SUCCESS);
}

t_bunny_response        loop(void *pass)
{
  t_data                *data;
  t_bunny_key           key;

  data = (t_data*)pass;
  key = &echap_down;
  bunny_set_key_response(key);
  bunny_blit(&data->graph->win->buffer, &data->graph->pix->clipable, NULL);
  bunny_blit(&data->graph->win->buffer, data->graph->pic, NULL);
  bunny_display(data->graph->win);
  return (GO_ON);
}

int			init_win(t_data *data)
{
  data->infos.nbr_links /= 2;
  if (!(data->graph = malloc(sizeof(*data->graph))))
    return (ERROR);
  if (init_graph(data) == ERROR)
    return (ERROR);
  data->graph->win = bunny_start(1080, 720, false, "Lem-in");
  data->graph->pic = bunny_new_picture(1080, 720);
  data->graph->pix = bunny_new_pixelarray(1080, 720);
  return (SUCCESS);
}

int                     main_loop(t_data *data)
{
  t_bunny_loop          loop_main;

  loop_main = &loop;
  bunny_set_loop_main_function(loop_main);
  bunny_loop(data->graph->win, 100, data);
  bunny_stop(data->graph->win);
  bunny_delete_clipable(data->graph->pic);
  bunny_delete_clipable(&data->graph->pix->clipable);
  return (SUCCESS);
}
