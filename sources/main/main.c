/*
** main.c for main in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:54:50 2016 Thomas LE MOULLEC
** Last update Wed Apr 20 10:37:38 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

void		free_nodes(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->infos.nbr_nodes + 1)
    {
      my_free(data->nodes[i].name);
      my_free(data->nodes[i].id_pipe);
      i++;
    }
  my_free(data->nodes);
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)av;
  if ((parser(ac, &data)) == ERROR)
    return (ERROR);
  if (algo(&data, 0, 0) == ERROR)
    return (ERROR);
  if (algo_ant(&data) == ERROR)
    return (ERROR);
  free_nodes(&data);
  free(data.parser.buffer);
  return (SUCCESS);
}
