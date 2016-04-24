/*
** main.c for main in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:54:50 2016 Thomas LE MOULLEC
** Last update Sun Apr 24 17:00:52 2016 Thomas CHABOT
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
    {
      if (data.parser.buffer != NULL)
	my_putstr(data.parser.buffer, 1);
      return (1);
    }
  if (algo(&data, 0, 0) == ERROR)
    {
      my_putstr(data.parser.buffer, 1);
      return (1);
    }
  if (algo_ant(&data) == ERROR)
    {
      my_putstr(data.parser.buffer, 1);
      return (1);
    }
  free_nodes(&data);
  free(data.parser.buffer);
  return (0);
}
