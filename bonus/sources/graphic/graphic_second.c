/*
** graphic_second.c for graphic_second in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin/bonus/sources/graphic
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Apr 20 11:08:43 2016 leo LE DIOURON
** Last update Wed Apr 20 11:22:20 2016 leo LE DIOURON
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

int                     init_links(t_data *data, int i)
{
  int                   j;
  int                   nb;

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
          data->graph->links[nb][1].x = data->graph->nodes \
	    [data->nodes[i].id_pipe[j]].x;
          data->graph->links[nb][1].y = data->graph->nodes \
	    [data->nodes[i].id_pipe[j]].y;
          j++;
          nb++;
        }
      i++;
    }
  return (SUCCESS);
}

int                     init_graph(t_data *data)
{
  int                   i;

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

t_bunny_position	*move_pos(t_bunny_position *pos, t_data *d, int j)
{
  pos[0].x = d->graph->nodes[d->best_paths[d->ant[j].num_path] \
			     [d->ant[j].pos_path - 1]].x;
  pos[0].y = d->graph->nodes[d->best_paths[d->ant[j].num_path] \
			     [d->ant[j].pos_path - 1]].y;
  pos[1].x = d->graph->nodes[d->best_paths[d->ant[j].num_path] \
			     [d->ant[j].pos_path]].x;
  pos[1].y = d->graph->nodes[d->best_paths[d->ant[j].num_path] \
			     [d->ant[j].pos_path]].y;

  return (pos);
}

int                     move_ant_graph(t_data *d)
{
  int                   j;
  unsigned int          *color;
  t_bunny_position      *pos;

  j = 0;
  if (!(pos = malloc(sizeof(*pos) * 2)))
    return (ERROR);
  if (!(color = malloc(sizeof(*color) * 2)))
    return (ERROR);
  color[0] = GREEN;
  color[1] = GREEN;
  while (j < d->infos.nbr_ants && d->ant[j].flag != BEGIN)
    {
      if (d->ant[j].flag != FINISH)
        {
	  pos = move_pos(pos, d, j);
          bunny_set_line(&d->graph->pic->buffer, pos, color);
        }
      j++;
    }
  return (SUCCESS);
}