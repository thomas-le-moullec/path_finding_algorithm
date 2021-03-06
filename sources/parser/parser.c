/*
** parser.c for parser in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:56:42 2016 Thomas LE MOULLEC
** Last update Sat Apr 23 18:06:51 2016 leo LE DIOURON
*/

#include "lem_in.h"

int		take_parser(t_data *data)
{
  int		ret;

  if (!(data->parser.buffer = malloc(READ_SIZE + 1)))
    return (ERROR);
  if ((ret = read(0, data->parser.buffer, READ_SIZE)) <= 0)
    return (ERROR);
  data->parser.buffer[ret] = '\0';
  if ((data->infos.nbr_nodes = fill_nbr_nodes(data)) <= 1)
    return (error_nbr_nodes());
  if (!(data->nodes = malloc(sizeof(*data->nodes) * \
			     (data->infos.nbr_nodes + 1))))
    return (error_malloc());
  if ((init_nodes(data)) == ERROR)
    return (ERROR);
  if ((check_buffer(data)) == ERROR)
    return (ERROR);
  if ((fill_links(data)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		end_parser(t_data *data)
{
  if (data->parser.nbr_start != 1)
    return (error_default("There is an Error, need one start\n"));
  if (data->parser.nbr_end != 1)
    return (error_default("There is an Error, need one end\n"));
  return (SUCCESS);
}

int		parser(int ac, t_data *data)
{
  if (ac != 1)
    return (error_args());
  if ((init_parser(data)) == ERROR)
    return (ERROR);
  if (take_parser(data) == ERROR)
    return (ERROR);
  if (end_parser(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
