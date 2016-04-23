/*
** main.c for main in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:54:50 2016 Thomas LE MOULLEC
** Last update Sat Apr 23 18:07:34 2016 leo LE DIOURON
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

  if (!(data.parser.buffer = malloc(READ_SIZE + 1)))
    return (ERROR);
  (void)av;
  if ((parser(ac, &data)) == ERROR)
    return (ERROR);
  data.time = my_get_nbr(av[1]);
  if (init_win(&data) == ERROR)
    return (ERROR);
  if (algo(&data, 0, 0) == ERROR)
    return (ERROR);
  if (algo_ant(&data) == ERROR)
    return (ERROR);
  main_loop(&data);
  free_nodes(&data);
  free(data.parser.buffer);
  return (SUCCESS);
}
