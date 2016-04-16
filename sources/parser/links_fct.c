/*
** links_fct.c for links_fct in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Apr 16 11:38:57 2016 Thomas LE MOULLEC
** Last update Sat Apr 16 11:40:26 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             static_ptr(t_data *data, int *i)
{
  data->infos.ret = *i - 2;
  while (data->parser.buffer[data->infos.ret] != '\0' && \
         data->parser.buffer[data->infos.ret] != '\n')
    data->infos.ret--;
  data->infos.ret++;
  return (SUCCESS);
}

int             links_cmp(t_data *data, char *line, char *tmp, char *other)
{
  int           j;

  j = 0;
  while (j < data->infos.nbr_nodes && \
         (my_strcmp(tmp, data->nodes[j].name) == ERROR))
    j++;
  if (data->nodes[j].name == NULL || data->nodes[j].id == ERROR)
    return (error_link(line, data));
  data->nodes[j].nb_pipe++;
  data->infos.nbr_links++;
  j = 0;
  while (j < data->infos.nbr_nodes && \
         (my_strcmp(other, data->nodes[j].name) == ERROR))
    j++;
  if (data->nodes[j].name == NULL || data->nodes[j].id == ERROR)
    return (error_link(line, data));
  data->nodes[j].nb_pipe++;
  return (SUCCESS);
}

char            *links_cpy(int *j, char *line)
{
  char          *tmp;

  tmp = NULL;
  while (line[*j] != '\0' && line[*j] != '-')
    *j = *j + 1;
  if (!(tmp = malloc(sizeof(*tmp) * (*j + 1))))
    return (NULL);
  *j = 0;
  while (line[*j] != '\0' && line[*j] != '-')
    {
      tmp[*j] = line[*j];
      *j = *j + 1;
    }
  if (line[*j] != '-')
    return (NULL);
  tmp[*j] = '\0';
  *j = *j + 1;
  return (tmp);
}

char            *other_cpy(int *j, char *line, int i)
{
  char          *tmp;

  tmp = NULL;
  while (line[i] != '\0' && line[i] != '-')
    i++;
  if (line[i] != '-')
    return (NULL);
  i++;
  *j = i;
  while (line[*j] != '\0')
    *j = *j + 1;
  if (!(tmp = malloc(sizeof(*tmp) * (*j - i + 1))))
    return (NULL);
  *j = i;
  i = 0;
  while (line[*j] != '\0')
    {
      tmp[i] = line[*j];
      *j = *j + 1;
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}
