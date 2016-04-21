/*
** algo.c for algo in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 11:07:26 2016 leo LE DIOURON
** Last update Thu Apr 21 14:59:01 2016 Thomas CHABOT
*/

#include "lem_in.h"

int	flag_nodes_path(t_data *data, int *history, int best_size)
{
  int	i;

  i = 0;
  while (history[i] != -1)
    {
      if (data->nodes[history[i]].flag == EMPTY)
	data->nodes[history[i]].flag = FULL;
      i++;
    }
  if (i > (data->infos.nbr_ants + best_size))
    return (ERROR);
  return (SUCCESS);
}

int	check_history(int *history, int pos)
{
  int	i;

  i = 0;
  while (history[i] != -1)
    if (history[i++] == pos)
      return (ERROR);
  return (SUCCESS);
}

int     find_best_path(t_data *data, int f)
{
  int   i;

  i = 0;
  if (f > 7000)
    return (ERROR);
  while (i < data->nodes[data->path->pos].nb_pipe)
    {
      if (check_history(data->path->history, \
			data->nodes[data->path->pos].id_pipe[i]) \
          == SUCCESS && data->nodes[data->path->pos].flag != FULL)
	cpy_elem(&data->path, data->nodes[data->path->pos].id_pipe[i]);
      i++;
    }
  if (data->path->prev == data->path \
      && data->nodes[data->path->pos].flag != END)
    return (ERROR);
  delete_elem(&data->path);
  if (data->nodes[data->path->pos].flag != END)
    if (find_best_path(data, f + 1) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int	algo_loop(t_data *data, int *a, int i, int *j)
{
  if (creat_list(data) == ERROR)
    return (ERROR);
  if (find_best_path(data, 0) == ERROR)
    *a = 1;
  if (*j == 0)
    while (data->path->history[i] != -1)
      i++;
  if (flag_nodes_path(data, data->path->history, i) == ERROR)
    *a = 1;
  if (*a == 0)
    data->best_paths[(*j)++] = data->path->history;
  delete_elem(&data->path);
  return (0);
}

int	algo(t_data *data, int a, int j)
{
  int	nb_turn;
  int	i;

  i = 0;
  if (creat_list(data) == ERROR)
    return (ERROR);
  nb_turn = data->nodes[data->infos.start].nb_pipe;
  if (nb_turn > data->infos.nbr_ants)
    nb_turn = data->infos.nbr_ants;
  data->best_paths = NULL;
  if (!(data->best_paths = malloc(sizeof(*data->best_paths) * (nb_turn + 1))))
    return (ERROR);
  while (j < nb_turn && a == 0)
    algo_loop(data, &a, i, &j);
  data->best_paths[j] = NULL;
  return (SUCCESS);
}
