/*
** functions.c for functions in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 17:15:20 2016 Thomas LE MOULLEC
** Last update Fri Apr 22 14:29:54 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             simple_com_fct(int *i, char *line, t_data *data)
{
  *i = *i;
  data = data;
  if (line[0] == '#' && line[1] == '#')
    return (error_simple_com(data, line));
  my_free(line);
  return (SUCCESS);
}

int             links_fct(int *i, char *line, t_data *data)
{
  int           j;
  char          *tmp;
  char          *other;
  static int    first = 0;

  j = 0;
  if (first++ == 0)
    static_ptr(data, i);
  tmp = NULL;
  other = NULL;
  if ((tmp = links_cpy(&j, line)) == NULL)
    return (error_malloc());
  if ((other = other_cpy(&j, line, 0)) == NULL)
    return (error_malloc());
  if ((links_cmp(data, line, tmp, other)) == ERROR)
    return (ERROR);
  data->infos.nbr_links++;
  my_free(tmp);
  my_free(other);
  my_free(line);
  return (SUCCESS);
}

int		nodes_fct(int *i, char *line, t_data *data)
{
  *i = *i;
  if ((valid_node(line)) == ERROR)
    return (error_node(data, line));
  data->nodes[data->infos.j].flag = EMPTY;
  data->nodes[data->infos.j].id = data->infos.j;
  data->nodes[data->infos.j].name = find_name(line);
  if ((data->nodes[data->infos.j].name == NULL))
    return (error_node(data, line));
  data->infos.j++;
  my_free(line);
  return (SUCCESS);
}
