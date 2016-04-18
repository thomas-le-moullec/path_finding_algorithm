/*
** graphic.c for graphic in /home/tchikl_h/rendu/B2/CPE/CPE_2015_Lemin/bonus/sources/graphic
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Sat Apr 16 11:25:12 2016 Hervé TCHIKLADZE
** Last update Mon Apr 18 21:15:12 2016 Hervé TCHIKLADZE
*/

#include "lem_in.h"

t_bunny_response        echap_down(t_bunny_event_state  state,
                                   t_bunny_keysym       key,
                                   void                 *your_data)
{
  (void)your_data;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

int			init_links(t_data *data, int i)
{
  int			j;
  int			nb;

  nb = 0;
  while (nb < data->infos.nbr_links)
    {
      j = 0;
      while (j < data->nodes[i].nb_pipe)
	{
	  if (!(data->graph->links[nb] = malloc(sizeof(t_bunny_position) * 2)))
	    return (ERROR);
	  data->graph->links[nb][0].x = data->graph->nodes[i].x;
	  data->graph->links[nb][0].y = data->graph->nodes[i].y;
	  data->graph->links[nb][1].x = data->graph->nodes[data->nodes[i].id_pipe[j]].x;
	  data->graph->links[nb][1].y = data->graph->nodes[data->nodes[i].id_pipe[j]].y;
	  j++;
	  nb++;
	}
      i++;
    }
  return (SUCCESS);
}

int			init_graph(t_data *data)
{
  int			i;

  srand(time(NULL));
  i = 0;
  data->graph->nodes = NULL;
  if (!(data->graph->nodes = \
	malloc(sizeof(t_bunny_position) * data->infos.nbr_nodes)))
    return (ERROR);
  if (!(data->graph->links = \
	malloc(sizeof(t_bunny_position *) * data->infos.nbr_links * 2)))
    return (ERROR);
  while (i < data->infos.nbr_nodes)
    {
      data->graph->nodes[i].x = rand() % 1080;
      data->graph->nodes[i].y = rand() % 720;
      i++;
    }
  if (init_links(data, 0 == ERROR))
    return (ERROR);
  return (SUCCESS);
}

int			move_ant_graph(t_data *data)
{
  int			j;
  unsigned int		*color;
  t_bunny_position	*pos;

  j = 0;
  if (!(pos = malloc(sizeof(*pos) * 2)))
    return (ERROR);
  if (!(color = malloc(sizeof(*color) * 2)))
    return (ERROR);
  color[0] = GREEN;
  color[1] = GREEN;
  while (j < data->infos.nbr_ants && data->ant[j].flag != BEGIN)
    {
      if (data->ant[j].flag != FINISH)
	{
	  pos[0].x = data->graph->nodes[data->best_paths[data->ant[j].num_path][data->ant[j].pos_path - 1]].x;
	  pos[0].y = data->graph->nodes[data->best_paths[data->ant[j].num_path][data->ant[j].pos_path - 1]].y;
	  pos[1].x = data->graph->nodes[data->best_paths[data->ant[j].num_path][data->ant[j].pos_path]].x;
	  pos[1].y = data->graph->nodes[data->best_paths[data->ant[j].num_path][data->ant[j].pos_path]].y;
	  bunny_set_line(&data->graph->pic->buffer, pos, color);
	}
      j++;
    }
  return (SUCCESS);
}

int			draw_nodes(t_data *data)
{
  int			i;
  unsigned int		color;

  i = 0;
  while (i < data->infos.nbr_nodes)
    {
      color = RED;
      if (data->nodes[i].flag == START)
	color = BLUE;
      if (data->nodes[i].flag == END)
	color = YELLOW;
      tekcircle(data->graph->pix, data->graph->nodes[i], color, 10);
      i++;
    }
  if (move_ant_graph(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			draw_links(t_data *data)
{
  int			i;
  int			j;
  int			nb;
  unsigned int		*color2;

  if (!(color2 = malloc(sizeof(*color2) * 2)))
    return (ERROR);
  color2[0] = WHITE;
  color2[1] = WHITE;
  i = 0;
  nb = 0;
  while (i < data->infos.nbr_nodes)
    {
      if (nb < data->infos.nbr_links)
        j = 0;
      while (j++ < data->nodes[i].nb_pipe && data->graph->links[nb] != NULL)
	bunny_set_line(&data->graph->pic->buffer, data->graph->links[nb++], color2);
      i++;
    }
  if (draw_nodes(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

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