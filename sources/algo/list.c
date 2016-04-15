/*
** list.c for list in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin/sources/algo
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 15 14:38:28 2016 leo LE DIOURON
** Last update Fri Apr 15 21:30:47 2016 leo LE DIOURON
*/

#include "lem_in.h"

int		cpy_elem(t_path **actual_path, int new_pos)
{
  t_path	*new_path;
  int		i;

  i = 0;
  if (!(new_path = malloc(sizeof(*new_path))))
    return (ERROR);
  new_path->pos = new_pos;
  new_path->cmpt = (*actual_path)->cmpt + 1;
  if (!(new_path->history = malloc(sizeof(*new_path->history) * \
				    (new_path->cmpt + 1))))
    return (ERROR);
  while ((*actual_path)->history[i] != -1)
    {
      new_path->history[i] = (*actual_path)->history[i];
      i++;
    }
  new_path->history[i++] = new_pos;
  new_path->history[i] = -1;
  i = 0;
  while (new_path->history[i] != -1)
    printf("___%d___\n", new_path->history[i++]);
  printf("\n");
  new_path->next = (*actual_path);
  new_path->prev = (*actual_path)->prev;
  (*actual_path)->prev->next = new_path;
  (*actual_path)->prev = new_path;
  return (SUCCESS);
}

void		delete_elem(t_path **actual_path)
{
  (*actual_path)->next->prev = (*actual_path)->prev;
  (*actual_path)->prev->next = (*actual_path)->next;
  (*actual_path) = (*actual_path)->next;
}

int		creat_list(t_data *data)
{
  int		cmpt;

  cmpt = 0;
  while (data->nodes[cmpt].flag != START)
    cmpt++;
  data->infos.start = cmpt;
  if (!(data->path = malloc(sizeof(*data->path))))
    return (ERROR);
  data->path->next = data->path;
  data->path->prev = data->path;
  data->path->pos = cmpt;
  data->path->cmpt = 1;
  if (!(data->path->history = malloc(sizeof(*data->path->history) * 2)))
    return (ERROR);
  data->path->history[0] = cmpt;
  data->path->history[1] = -1;
  return (SUCCESS);
}
