/*
** fill_id.c for fill_id in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Fri Apr 15 14:49:36 2016 Thomas LE MOULLEC
** Last update Fri Apr 15 18:07:48 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             fill_id_pipe(t_data *data, int i)
{
  int           j;

  j = 0;
  while (data->infos.tubes[j] != NULL)
    {
      if (my_strcmp_colon(data->infos.tubes[j], \
			  data->nodes[i].name) == SUCCESS)
        {
          data->nodes[i].id_pipe[data->nodes[i].cmpt] = my_cut_id(data, j);
          if (data->nodes[i].id_pipe[data->nodes[i].cmpt] == ERROR)
            return (ERROR);
          data->nodes[i].cmpt++;
        }
      j++;
    }
  return (SUCCESS);
}

int             my_cut_id(t_data *data, int j)
{
  char          *tmp;
  int           x;
  int           ptr;

  x = 0;
  tmp = NULL;
  while (data->infos.tubes[j][x] != '\0' && data->infos.tubes[j][x] != '-')
    x++;
  if (data->infos.tubes[j][x] != '-')
    return (error_link(data->infos.tubes[j], data));
  x++;
  ptr = x;
  while (data->infos.tubes[j][x++] != '\0');
  if (!(tmp = malloc(sizeof(*tmp) * (x - ptr + 1))))
    return (error_malloc());
  if ((tmp = my_strcpy_ptr(data->infos.tubes[j], tmp, ptr)) == NULL)
    return (error_malloc());
  x = 0;
  while (x < data->infos.nbr_nodes)
    {
      if (my_strcmp(data->nodes[x].name, tmp) == SUCCESS)
        return (data->nodes[x].id);
      x++;
    }
  return (error_correspondance(tmp, data));
}

int             my_strcmp_colon(char *tube, char *name)
{
  int           j;

  j = 0;
  while (tube[j] != '\0' && tube[j] != '-')
    {
      if (tube[j] != name[j])
        return (ERROR);
      j++;
    }
  return (SUCCESS);
}
