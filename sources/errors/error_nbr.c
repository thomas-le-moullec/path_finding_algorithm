/*
** error_nbr.c for error_nbr in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/errors
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Apr 16 11:27:08 2016 Thomas LE MOULLEC
** Last update Sat Apr 16 11:29:17 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             error_nbr_nodes()
{
  my_putstr("There is an Error, need at least two nodes\n", 2);
  return (ERROR);
}

int             error_nbr_ants()
{
  my_putstr("There is an Error, the number of ants is not correct\n", 2);
  return (ERROR);
}
