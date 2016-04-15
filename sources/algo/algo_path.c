/*
** algo.c for algo in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 11:07:26 2016 leo LE DIOURON
** Last update Fri Apr 15 21:35:25 2016 leo LE DIOURON
*/

#include "lem_in.h"

void	flag_nodes_path(t_data *data, int *history)
{
  int	i;

  i = 0;
  while (history[i] != -1)
    {
      if (data->nodes[history[i++]].flag == EMPTY)
	data->nodes[history[i++]].flag = FULL;
      i++;
    }
}

int	find_best_path(t_data *data)
{
  int	i;
  int	f;

  i = 0;
  f =0;
  /*  printf("name = %s --> nb = %d\n", data->nodes[data->path->pos].name, data->nodes[data->path->pos].nb_pipe);*/
  while (i <= data->nodes[data->path->pos].nb_pipe)
    {
      printf("on envoie --> %d\n", data->nodes[data->path->pos].id_pipe[i]);
      cpy_elem(&data->path, data->nodes[data->path->pos].id_pipe[i++]);
    }
  printf("------------------------------\n\n");
  printf("\n----%d-----\n", data->path->pos);
  while (data->path->history[f] != -1)
    printf("%d\n", data->path->history[f++]);
  delete_elem(&data->path);
  printf("\n----%d-----\n", data->path->pos);
  while (data->path->history[f] != -1)
    printf("%d\n", data->path->history[f++]);
  printf("------------------------------\n\n");
  if (data->nodes[data->path->pos].flag != END)
    find_best_path(data);
  return (SUCCESS);
}

int	algo(t_data *data)
{
  int	nb_turn;
  int	j;

  j = 0;
  if (creat_list(data) == ERROR)
    return (ERROR);
  nb_turn = data->nodes[data->infos.start].nb_pipe;
  if (!(data->best_paths = malloc(sizeof(*data->best_paths) * (nb_turn + 1))))
    return (ERROR);
  while (j < nb_turn)
    {
      if (find_best_path(data) == ERROR)
	return (ERROR);
      flag_nodes_path(data, data->path->history);
      data->best_paths[j] = data->path->history;
      j++;
    }
  data->best_paths[j] = NULL;
  return (SUCCESS);
}
