/*
** error_default.c for error_default in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:42:38 2016 Thomas LE MOULLEC
** Last update Sun Apr 17 18:43:23 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		error_default(char *str)
{
  my_putstr(str, 2);
  return (ERROR);
}
