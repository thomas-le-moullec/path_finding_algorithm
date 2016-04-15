/*
** functions.c for functions in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 17:15:20 2016 Thomas LE MOULLEC
** Last update Fri Apr 15 13:46:27 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		simple_com_fct(int *i, char *line, t_data *data)
{
  *i = *i;
  data = data;
  if (line[0] == '#' && line[1] == '#')
    {
      write(2, "Error comment line : ", 21);
      my_put_nbr(data->parser.nbr_line);
      return (ERROR);
    }
  my_free(line);
  return (SUCCESS);
}

char		*links_cpy(int j, char *line)
{
  char		*tmp;

  tmp = NULL;
  while (line[j] != '\0' && line[j] != '-')
    j++;
  if (!(tmp = malloc(sizeof(*tmp) * (j + 1))))
    return (NULL);
  j = 0;
  while (line[j] != '\0' && line[j] != '-')
    {
      tmp[j] = line[j];
      j++;
    }
  tmp[j] = '\0';
  return (tmp);
}

int		links_fct(int *i, char *line, t_data *data)
{
  int		j;
  char		*tmp;
  static int	first = 0;

  j = 0;
  if (first == 0)
    {
      data->infos.ret = *i - 2;
      while (data->parser.buffer[data->infos.ret] != '\0' && \
	     data->parser.buffer[data->infos.ret] != '\n')
	data->infos.ret--;
      data->infos.ret++;
    }
  first++;
  tmp = NULL;
  if ((valid_link(line)) == ERROR)
    return (ERROR);
  if ((tmp = links_cpy(j, line)) == NULL)
    return (ERROR);
  while (j < data->infos.nbr_nodes && \
	 (my_strcmp(tmp, data->nodes[j].name) == ERROR))
    j++;
  if (data->nodes[j].name == NULL || data->nodes[j].id == ERROR)
    return (ERROR);
  data->nodes[j].nb_pipe++;
  data->infos.nbr_links++;
  my_free(tmp);
  my_free(line);
  return (SUCCESS);
}

int		nodes_fct(int *i, char *line, t_data *data)
{
  *i = *i;
  if ((valid_node(line)) == ERROR)
    return (ERROR);
  data->nodes[data->infos.j].flag = EMPTY;
  data->nodes[data->infos.j].id = data->infos.j;
  data->nodes[data->infos.j].name = find_name(line);
  data->infos.j++;
  if ((data->nodes[data->infos.j].name = NULL))
    return (ERROR);
  my_free(line);
  return (SUCCESS);
}
