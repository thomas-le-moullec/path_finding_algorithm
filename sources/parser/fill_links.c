/*
** fill_links.c for fill_links in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 22:51:01 2016 Thomas LE MOULLEC
** Last update Fri Apr 15 19:51:25 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		count_line(t_data *data, int i)
{
  int		cmpt;

  cmpt = 0;
  while (data->parser.buffer[i] != '\0' && data->parser.buffer[i] != '\n')
    {
      cmpt++;
      i++;
    }
  return (cmpt);
}

int		loop_tubes(t_data *data, int *y, int i, int x)
{
  while (data->parser.buffer[i] != '\0')
    {
      x = 0;
      if (data->parser.buffer[i] == '#')
	while (data->parser.buffer[i] != '\0' && \
	       data->parser.buffer[i++] != '\n');
      if (!(data->infos.tubes[*y] = malloc(sizeof(char) * \
					  (count_line(data, i) + 1))))
	return (error_malloc());
      while (data->parser.buffer[i] != '\0' && data->parser.buffer[i] != '\n')
	{
	  data->infos.tubes[*y][x] = data->parser.buffer[i];
	  x++;
	  i++;
	}
      data->infos.tubes[*y][x] = '\0';
      if (data->parser.buffer[i] != '\0')
	i++;
      *y = *y + 1;
    }
  return (SUCCESS);
}

int		fill_tubes(t_data *data)
{
  int		i;
  int		x;
  int		y;

  y = 0;
  x = 0;
  i = data->infos.ret;
  if (!(data->infos.tubes = malloc(sizeof(char *) * \
				   (data->infos.nbr_links + 1))))
    return (ERROR);
  if (loop_tubes(data, &y, i, x) == ERROR)
    return (ERROR);
  data->infos.tubes[y] = NULL;
  return (SUCCESS);
}

int		fill_links(t_data *data)
{
  int		i;

  i = 0;
  if ((fill_tubes(data)) == ERROR)
    return (ERROR);
  while (i < data->infos.nbr_nodes)
    {
      if (!(data->nodes[i].id_pipe = malloc(sizeof(char) * \
					    data->nodes[i].nb_pipe)))
	return (error_malloc());
      data->nodes[i].cmpt = 0;
      if ((fill_id_pipe(data, i)) == ERROR)
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}
