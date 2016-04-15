/*
** error_args.c for error_args in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/errors
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Fri Apr 15 15:16:38 2016 Thomas LE MOULLEC
** Last update Fri Apr 15 19:14:42 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		error_args()
{
  my_putstr("There is an Error because ./lem_in need only one argument\n", 2);
  return (ERROR);
}

int		error_reading()
{
  my_putstr("There is an Error of reading on the standard entry\n", 2);
  return (ERROR);
}

int		error_nbr_nodes()
{
  my_putstr("There is an Error, need at least two nodes\n", 2);
  return (ERROR);
}

int		error_nbr_ants()
{
  my_putstr("There is an Error, the number of ants is not correct\n", 2);
  return (ERROR);
}

int		error_malloc()
{
  my_putstr("There is an Error, one Malloc crashed\n", 2);
  return (ERROR);
}

int		error_copying(t_data *data)
{
  my_putstr("Error to copy the line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int		error_link(char *line, t_data *data)
{
  my_putstr("Error with the tube : ", 2);
  my_putstr(line, 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int		error_correspondance(char *line, t_data *data)
{
  my_putstr("Error with the link : ", 2);
  my_putstr(line, 2);
  my_putstr(" There is no correspondance with the name", 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int		error_node(t_data *data, char *line)
{
  my_putstr("Error with the node : ", 2);
  my_putstr(line, 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int		error_type(t_data *data, char *line)
{
  my_putstr("Error with the line : ", 2);
  my_putstr(line, 2);
  my_putstr(" number : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int		error_simple_com(t_data *data, char *line)
{
  my_putstr("Error with the comment : ", 2);
  my_putstr(line, 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line, 2);
  my_putchar('\n', 2);
  return (ERROR);
}
