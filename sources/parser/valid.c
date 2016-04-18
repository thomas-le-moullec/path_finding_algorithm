/*
** valid.c for valid in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 20:49:01 2016 Thomas LE MOULLEC
** Last update Mon Apr 18 20:43:00 2016 Thomas CHABOT
*/

#include "lem_in.h"

int             valid_node(char *line)
{
  int           i;

  i = 0;
  while (line[i] != '\0' && line[i] != ' ')
    i++;
  if (line[i] != ' ')
    return (ERROR);
  i++;
  while (line[i] >= '0' && line[i] <= '9')
    i++;
  if (line[i] != ' ')
    return (ERROR);
  i++;
  while (line[i] >= '0' && line[i] <= '9')
    i++;
  if (line[i] != '\0')
    return (ERROR);
  return (SUCCESS);
}
