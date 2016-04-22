/*
** error_args.c for error_args in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/errors
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Fri Apr 15 15:16:38 2016 Thomas LE MOULLEC
** Last update Fri Apr 22 14:18:17 2016 Thomas LE MOULLEC
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

int		error_malloc()
{
  my_putstr("There is an Error, one Malloc crashed\n", 2);
  return (FATAL_ERROR);
}

int		error_copying(t_data *data)
{
  my_putstr("Error to copy the line : ", 2);
  my_put_nbr(data->parser.nbr_line + 1, 2);
  my_putchar('\n', 2);
  return (FATAL_ERROR);
}
