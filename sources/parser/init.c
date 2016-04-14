/*
** init.c for init in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 19:13:54 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 23:47:05 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		init_nodes(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->infos.nbr_nodes + 1)
    {
      data->nodes[i].flag = ERROR;
      data->nodes[i].id = ERROR;
      data->nodes[i].name = NULL;
      data->nodes[i].nb_pipe = 0;
      data->nodes[i].id_pipe = NULL;
      i++;
    }
  return (SUCCESS);
}

int             init_infos(t_data *data)
{
  data->infos.j = 0;
  data->infos.ret = 0;
  data->infos.nbr_ants = 0;
  data->infos.nbr_nodes = 0;
  data->infos.nbr_links = 0;
  data->infos.tubes = NULL;
  return (SUCCESS);
}

int             init_functions(t_data *data)
{
  data->fct[0] = double_com_fct;
  data->fct[1] = simple_com_fct;
  data->fct[2] = links_fct;
  data->fct[3] = nodes_fct;
  return (SUCCESS);
}

int             init_parser(t_data *data)
{
  data->parser.nbr_start = 0;
  data->parser.nbr_end = 0;
  data->parser.nbr_line = 0;
  if ((init_functions(data)) == ERROR)
    return (ERROR);
  if ((init_infos(data)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
