/*
** fill_nbr.c for fill_nbr in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 19:00:35 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 22:06:31 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             fill_nbr_ants(t_data *data, char *line)
{
  if ((data->infos.nbr_ants = my_get_nbr(line)) == ERROR)
    {
      my_free(line);
      return (ERROR);
    }
  my_free(line);
  return (SUCCESS);
}

int             fill_nbr_nodes(t_data *data)
{
  int           i;
  int           nbr;

  i = 0;
  nbr = -1;
  while (data->parser.buffer[i] != '\0' && data->parser.buffer[i] != '-')
    {
      if (data->parser.buffer[i] == '#')
	  while (data->parser.buffer[i] != '\0' && \
		 data->parser.buffer[i++] != '\n');
      if (data->parser.buffer[i] == '\n')
	nbr++;
      if (data->parser.buffer[i] != '\0')
	i++;
    }
  return (nbr);
}
