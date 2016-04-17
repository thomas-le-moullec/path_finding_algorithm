/*
** algo.c for algo in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 11:07:26 2016 leo LE DIOURON
** Last update Sun Apr 17 17:25:53 2016 leo LE DIOURON
*/

#include "lem_in.h"

void	flag_nodes_path(t_data *data, int *history)
{
  int	i;

  i = 0;
  while (history[i] != -1)
    {
      if (data->nodes[history[i]].flag == EMPTY)
	data->nodes[history[i]].flag = FULL;
      i++;
    }
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



int     find_best_path(t_data *data, int f, int j)
{
  int   i;
  int   h;

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
  delete_elem(&data->path);
  if (data->path->prev == data->path)
    return (ERROR);
  if (data->nodes[data->path->pos].flag != END)
    if (find_best_path(data, f + 1, j) == ERROR)
      return (ERROR);
  return (SUCCESS);
  }

int	algo(t_data *data)
{
  int	nb_turn;
  int	j;
  int	a;

  int	i;

  j = 0;
  a = 0;
  if (creat_list(data) == ERROR)
    return (ERROR);
  nb_turn = data->nodes[data->infos.start].nb_pipe;
  printf("nb_turn = %d\n", nb_turn);
  if (nb_turn > data->infos.nbr_ants)
    nb_turn = data->infos.nbr_ants;
  /*  if (nb_turn > 10)
      nb_turn = 10;*/
  data->best_paths = NULL;
  if (!(data->best_paths = malloc(sizeof(*data->best_paths) * (nb_turn + 1))))
    return (ERROR);

  while (j < nb_turn && a == 0)
    {
      i = 0;
      printf("J vaut %d\n", j);
      if (creat_list(data) == ERROR)
	return (ERROR);
      if (find_best_path(data, 0, j) == ERROR)
	a = 1;
      while (data->path->history[i] != -1)
	{
	  printf("his[%d] = %d, ", i, data->path->history[i]);
	  i++;
	}
      printf("\n\n");
      flag_nodes_path(data, data->path->history);
      data->best_paths[j] = data->path->history;
      delete_elem(&data->path);
      j++;
    }
  data->best_paths[j] = NULL;
  return (SUCCESS);
}
