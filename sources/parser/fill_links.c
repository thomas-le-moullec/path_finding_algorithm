/*
** fill_links.c for fill_links in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 22:51:01 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 23:47:26 2016 Thomas LE MOULLEC
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

int		fill_tubes(t_data *data)
{
  int		i;
  int		x;
  int		y;

  y = 0;
  i = data->infos.ret;
  if (!(data->infos.tubes = malloc(sizeof(char *) * \
				   (data->infos.nbr_links + 1))))
    return (ERROR);
  while (data->parser.buffer[i] != '\0')
    {
      x = 0;
      if (data->parser.buffer[i] == '#')
	while (data->parser.buffer[i] != '\0' && data->parser.buffer[i++] != '\n');
      if (!(data->infos.tubes[y] = malloc(sizeof(char) * \
					  (count_line(data, i) + 1))))
	return (ERROR);
      while (data->parser.buffer[i] != '\0' && data->parser.buffer[i] != '\n')
	{
	  data->infos.tubes[y][x] = data->parser.buffer[i];
	  x++;
	  i++;
	}
      data->infos.tubes[y][x] = '\0';
      if (data->parser.buffer[i] != '\0')
	i++;
      y++;
    }
  data->infos.tubes[y] = NULL;
  return (SUCCESS);
}

int		my_strcmp_colon(char *tube, char *name)
{
  int		i;

  i = 0;
  while (tube[i] != '\0' && tube[i] != '-')
    {
      if (tube[i] != name[i])
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}

char		*cut_pipe(char *tube)
{
  int		i;
  int		j;
  char		*stock;

  i = 0;
  j = 0;
  stock = NULL;
  while (tube[i] != '\0' && tube[i] != '-')
    i++;
  if (tube[i] != '-')
    return (NULL);
  i++;
  while (tube[i] != '\0')
    {
      stock[j] = tube[i];
      i++;
      j++;
    }
  stock[j] = '\0';
  return (stock);
}

int		fill_id_pipe(t_data *data, int i)
{
  int		y;

  y = 0;
  while (data->infos.tubes[y] != NULL)
    {
      if (my_strcmp_colon(data->infos.tubes[y], data->nodes[i].name) == SUCCESS)
	{
	  if (!(data->nodes[i].id_pipe[data->nodes[i].cmpt] = malloc(sizeof(char) * (my_strlen(data->infos.tubes[y] + 1)))))
	    return (ERROR);
	  data->nodes[i].id_pipe[data->nodes[i].cmpt] = cut_pipe(data->infos.tubes[y]);
	  if ((data->nodes[i].id_pipe[data->nodes[i].cmpt]) == NULL)
	    return (ERROR);
	  data->nodes[i].cmpt++;
	}
      y++;
    }
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
	return (ERROR);
      data->nodes[i].cmpt = 0;
      if ((fill_id_pipe(data, i)) == ERROR)
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}
