/*
** main.c for main in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 10:37:00 2016 leo LE DIOURON
** Last update Thu Apr 14 22:49:36 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

void		free_nodes(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->infos.nbr_nodes + 1)
    {
      my_free(data->nodes[i].name);
      /*      my_free(data->nodes[i].id_pipe);*/
      i++;
    }
  my_free(data->nodes);
}

void		debug(t_data *data)
{
  int		i;

  i = 0;
  printf("nbr_links => %d | nbr_start => %d | nbr_end => %d | nbr_line => %d\n\n", data->infos.nbr_links, data->parser.nbr_start, data->parser.nbr_end, data->parser.nbr_line);
  while (i != data->infos.nbr_nodes)
    {
      printf("id => %d | name => %s | flag => %d | nb_pipe => %d\n", data->nodes[i].id, data->nodes[i].name, data->nodes[i].flag, data->nodes[i].nb_pipe);
      i++;
    }
  printf("------------------------------------------------\n\n");
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)av;
  if ((parser(ac, &data)) == ERROR)
    {
      printf("THERE IS AN ERROR\n");
      return (ERROR);
    }
  debug(&data);
  free_nodes(&data);
  return (SUCCESS);
}
