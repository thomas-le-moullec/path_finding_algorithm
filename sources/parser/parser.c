/*
** parser.c for parser.c in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 11:06:28 2016 leo LE DIOURON
** Last update Thu Apr 14 22:50:51 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		take_parser(t_data *data)
{
  int		ret;

  if ((ret = read(0, data->parser.buffer, READ_SIZE)) <= 0)
    return (ERROR);
  data->parser.buffer[ret] = '\0';
  if ((data->infos.nbr_nodes = fill_nbr_nodes(data)) <= 1)
    return (ERROR);
  if (!(data->nodes = malloc(sizeof(*data->nodes) * \
			     (data->infos.nbr_nodes + 1))))
    return (ERROR);
  if ((init_nodes(data)) == ERROR)
    return (ERROR);
  if ((check_buffer(data)) == ERROR)
    return (ERROR);
  if ((fill_links(data)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		parser(int ac, t_data *data)
{
  if (ac != 1)
    return (ERROR);
  if ((init_parser(data)) == ERROR)
    return (ERROR);
  if (take_parser(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
