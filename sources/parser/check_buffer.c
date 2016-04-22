/*
** check_buffer.c for check_buffer in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 18:58:54 2016 Thomas LE MOULLEC
** Last update Fri Apr 22 17:48:29 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

char            *copy_line(t_data *data, int *i)
{
  char          *stock;
  int           j;

  stock = NULL;
  j = *i;
  while (data->parser.buffer[j] != '\0' && data->parser.buffer[j] != '\n')
    j++;
  if (j == *i)
    return (NULL);
  if (!(stock = malloc(sizeof(*stock) * (j - *i + 1))))
    return (NULL);
  j = 0;
  while (data->parser.buffer[*i] != '\0' && data->parser.buffer[*i] != '\n')
    {
      stock[j++] = data->parser.buffer[*i];
      *i = *i + 1;
    }
  while (data->parser.buffer[*i] == '\n')
    *i = *i + 1;
  stock[j] = '\0';
  return (my_epur_str(stock));
}

int             find_type(t_data *data, char *line)
{
  int           i;

  i = 0;
  (void)data;
  if (my_strcmp(line, "##start") == SUCCESS \
      || my_strcmp(line, "##end") == SUCCESS)
    return (DOUBLE_COM);
  if (line[0] == '#')
    return (SIMPLE_COM);
  while (line[i] != '\0' && line[i] != '-' && line[i] != ' ')
    i++;
  if (line[i] == '-')
    return (LINKS);
  if (line[i] == ' ')
    return (NODES);
  return (ERROR);
}

int             check_line(t_data *data, int *i)
{
  int           ret;
  char          *line;

  line = NULL;
  if ((line = copy_line(data, i)) == NULL)
    return (error_copying(data));
  if (data->parser.nbr_line == 0)
    return (fill_nbr_ants(data, line));
  if ((ret = find_type(data, line)) == ERROR)
    return (error_type(data, line));
  if ((ret = ((data->fct[ret])(i, line, data))) == ERROR)
    return (ERROR);
  if (ret == FATAL_ERROR)
    return (FATAL_ERROR);
  return (SUCCESS);
}

int             check_buffer(t_data *data)
{
  int           i;
  int		ret;

  i = 0;
  while (data->parser.buffer[i] != '\0')
    {
      if ((ret = check_line(data, &i)) == ERROR)
	return (ERROR);
      if (ret == FATAL_ERROR)
	return (FATAL_ERROR);
      data->parser.nbr_line++;
      while (data->parser.buffer[i] == '\n')
        i++;
    }
  return (SUCCESS);
}
