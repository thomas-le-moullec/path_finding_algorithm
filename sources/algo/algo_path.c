/*
** algo.c for algo in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 11:07:26 2016 leo LE DIOURON
** Last update Sat Apr 16 17:01:59 2016 leo LE DIOURON
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
    {
      /*      printf("history[%d] = %d et pos = %d\n", i, history[i], pos);*/
      if (history[i++] == pos)
	return (ERROR);
    }
  return (SUCCESS);
}

int	find_best_path(t_data *data)
{
  int	i;

  i = 0;
  /*  printf("name = %s --> nb = %d\n", data->nodes[data->path->pos].name, data->nodes[data->path->pos].nb_pipe);*/
  while (i < data->nodes[data->path->pos].nb_pipe)
    {

      if (check_history(data->path->history, data->nodes[data->path->pos].id_pipe[i]) == SUCCESS && data->nodes[data->path->pos].flag != FULL)
	{
	  /*	  printf("cpy ---> %d\n", data->nodes[data->path->pos].id_pipe[i]);*/
	  cpy_elem(&data->path, data->nodes[data->path->pos].id_pipe[i]);
	}
      i++;
    }
  delete_elem(&data->path);
  if (data->path->prev == data->path)
    {
      return (ERROR);
    }
  /*  printf("LE NOUVEAU EST %d ---> le prev est %d\n", data->path->pos, data->path->prev->pos);*/
  /*  printf("Le nouveau path est %d\n", data->path->pos);
  while (data->path->history[f] != -1)
    printf("%d\n", data->path->history[f++]);
    printf("\n------------------------------\n\n");*/
  if (data->nodes[data->path->pos].flag != END)
    if (find_best_path(data) == ERROR)
      return (ERROR);
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
      if (creat_list(data) == ERROR)
	return (ERROR);
      if (find_best_path(data) == ERROR)
	{
	  j = nb_turn;
	}
      /*      printf("j = %d & nb_turn = %d\n", j, nb_turn);*/
      if (j != nb_turn)
	{
	  /*	  printf("Le tour numero %d est sorti !\n", j);*/
	  flag_nodes_path(data, data->path->history);
	  if (j < nb_turn)
	    data->best_paths[j] = data->path->history;
	  delete_elem(&data->path);
	  j++;
	}
    }
  data->best_paths[j] = NULL;
  return (SUCCESS);
}
