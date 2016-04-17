/*
** main.c for main in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:54:50 2016 Thomas LE MOULLEC
** Last update Sun Apr 17 18:56:32 2016 Thomas LE MOULLEC
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
  int		j;

  i = 0;
  printf("nbr_links => %d | nbr_start => %d | nbr_end => %d | nbr_line => %d\n\n", data->infos.nbr_links, data->parser.nbr_start, data->parser.nbr_end, data->parser.nbr_line);
  while (i != data->infos.nbr_nodes)
    {
      j = 0;
      printf("id => %d | name => %s | flag => %d | nb_pipe => %d | ", data->nodes[i].id, data->nodes[i].name, data->nodes[i].flag, data->nodes[i].nb_pipe);
      while (j < data->nodes[i].nb_pipe)
	{
	  printf("%d ème tube 'id : %d | ", j, data->nodes[i].id_pipe[j]);
	  j++;
	}
      printf("\n");
      i++;
    }
  printf("\n\n------------------------------------------------\n\n");
}

int		main(int ac, char **av)
{
  t_data	data;

  if (!(data.parser.buffer = malloc(100000000)))
    exit(-1);
  (void)av;
  if ((parser(ac, &data)) == ERROR)
    return (ERROR);
  debug(&data);
  algo(&data);
  algo_ant(&data);
  free_nodes(&data);
  free(data.parser.buffer);
  return (SUCCESS);
}
