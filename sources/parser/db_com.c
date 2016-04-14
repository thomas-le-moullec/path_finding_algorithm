/*
** db_com.c for db_com in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 19:49:20 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 22:11:14 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

char		*find_name(char *line)
{
  char		*stock;
  int		i;

  i = 0;
  stock = NULL;
  while (line[i] != '\0' && line[i] != ' ')
    i++;
  if (!(stock = malloc(sizeof(*stock) * (i + 1))))
    return (NULL);
  i = 0;
  while (line[i] != '\0' && line[i] != ' ')
    {
      stock[i] = line[i];
      i++;
    }
  stock[i] = '\0';
  return (stock);
}

int		my_start(int *i, t_data *data)
{
  char		*tmp;

  tmp = NULL;
  if ((tmp = copy_line(data, i)) == NULL)
    {
      printf("The copy is a fail : %d\n", data->parser.buffer[*i]);
      return (ERROR);
    }
  if ((valid_node(tmp)) == ERROR)
    {
      printf("ERROR the TMP : %s is not valid\n", tmp);
      return (ERROR);
    }
  data->parser.nbr_start++;
  data->nodes[data->infos.j].flag = START;
  data->nodes[data->infos.j].id = data->infos.j;
  data->nodes[data->infos.j].name = find_name(tmp);
  my_free(tmp);
  data->infos.j++;
  if ((data->nodes[data->infos.j].name = NULL))
    {
      printf("ERROR name is NULL\n");
      return (ERROR);
    }
  return (SUCCESS);
}

int		my_end(int *i, t_data *data)
{
  char		*tmp;

  tmp = NULL;
  if ((tmp = copy_line(data, i)) == NULL)
    {
      printf("ERROR with the copy\n");
      return (ERROR);
    }
  if ((valid_node(tmp)) == ERROR)
    {
      printf("ERROR : %s is not valid\n", tmp);
      return (ERROR);
    }
  data->parser.nbr_end++;
  data->nodes[data->infos.j].flag = END;
  data->nodes[data->infos.j].id = data->infos.j;
  data->nodes[data->infos.j].name = find_name(tmp);
  my_free(tmp);
  data->infos.j++;
  if ((data->nodes[data->infos.j].name = NULL))
    {
      printf("I didn't find the name =D\n");
      return (ERROR);
    }
  return (SUCCESS);
}

int             double_com_fct(int *i, char *line, t_data *data)
{
  if (line[2] == 's')
    {
      my_free(line);
      return (my_start(i, data));
    }
  if (line[2] == 'e')
    {
      my_free(line);
      return (my_end(i, data));
    }
  return (ERROR);
}
