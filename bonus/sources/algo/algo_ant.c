/*
** algo_ant.c for algo_ant in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin/sources/algo
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 15 16:51:19 2016 leo LE DIOURON
** Last update Wed Apr 20 16:57:07 2016 Hervé TCHIKLADZE
*/

#include "lem_in.h"

int	fill_ant(t_data *data)
{
  int	j;
  int	num;

  j = 0;
  num = 0;
  if (!(data->ant = malloc(sizeof(*data->ant) * (data->infos.nbr_ants + 1))))
    return (ERROR);
  while (j < data->infos.nbr_ants)
    {
      data->ant[j].num_path = num;
      data->ant[j].flag = BEGIN;
      data->ant[j].pos_path = 0;
      j++;
      num++;
      if (data->best_paths[num] == NULL)
	num = 0;
    }
  return (SUCCESS);
}

int	move_ants(t_data *data, int j)
{
  if (data->ant[j].flag != FINISH)
    {
      data->ant[j].pos_path++;
      if (data->best_paths[data->ant[j].num_path][data->ant[j].pos_path] == -1)
	data->ant[j].flag = FINISH;
    }
  j++;
  return (j);
}

int	algo_ant(t_data *data)
{
  int	j;
  int	num;

  if (data->best_paths[0] == NULL)
    return (error_default("There is an Error, there is no PATH\n"));
  if (fill_ant(data) == ERROR)
    return (ERROR);
  while (data->ant[data->infos.nbr_ants - 1].flag != FINISH)
    {
      j = 0;
      num = 0;
      while (j < data->infos.nbr_ants && data->ant[j].flag != BEGIN)
	j = move_ants(data, j);
      if (graphic(data) == ERROR)
        return (ERROR);
      usleep(data->time);
      while (data->best_paths[num] != NULL && j < data->infos.nbr_ants && \
	     data->ant[j].flag == BEGIN)
	{
	  data->ant[j++].flag = CURRENT;
	  num++;
	}
    }
  return (SUCCESS);
}
