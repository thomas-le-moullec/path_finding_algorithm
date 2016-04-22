/*
** error_act.c for error_act in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/errors
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Apr 16 11:27:37 2016 Thomas LE MOULLEC
** Last update Sat Apr 16 11:30:38 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             error_link(char *line, t_data *data)
{
  my_putstr("Error with the tube : ", 2);
  my_putstr(line, 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int             error_correspondance(char *line, t_data *data)
{
  my_putstr("Error with the link : ", 2);
  my_putstr(line, 2);
  my_putstr(" There is no correspondance with the name", 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int             error_node(t_data *data, char *line)
{
  my_putstr("Error with the node : ", 2);
  my_putstr(line, 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int             error_type(t_data *data, char *line)
{
  my_putstr("Error with the line : ", 2);
  my_putstr(line, 2);
  my_putstr(" number : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (ERROR);
}

int             error_simple_com(t_data *data, char *line)
{
  my_putstr("Error with the comment : ", 2);
  my_putstr(line, 2);
  my_putstr(" line : ", 2);
  my_put_nbr(data->parser.nbr_line, 2);
  my_putchar('\n', 2);
  return (ERROR);
}
