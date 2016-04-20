/*
** graphic_third.c for graphic_three in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin/bonus
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Apr 20 11:17:52 2016 leo LE DIOURON
** Last update Wed Apr 20 11:18:49 2016 leo LE DIOURON
*/

#include "lem_in.h"

int                     draw_nodes(t_data *data)
{
  int                   i;
  unsigned int          color;

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

int                     draw_links(t_data *data)
{
  int                   i;
  int                   j;
  int                   nb;
  unsigned int          *color2;

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
        bunny_set_line(&data->graph->pic->buffer, \
                       data->graph->links[nb++], color2);
      i++;
    }
  if (draw_nodes(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
