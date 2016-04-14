/*
** valid.c for valid in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 20:49:01 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 21:42:13 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int             valid_node(char *line)
{
  int           i;

  i = 0;
  /*  printf("We will check this line |%s|\n", line);*/
  while (line[i] != '\0' && line[i] != ' ')
    {
      //printf("line[%d] = > %c\n", i, line[i]);
      i++;
    }
  //printf("line[%d] = > %c\n", i, line[i]);
  if (line[i] != ' ')
    {
      //printf("a\n");
      return (ERROR);
    }
  i++;
  while (line[i] >= '0' && line[i] <= '9')
    {
      //printf("line[%d] = > %c\n", i, line[i]);
      i++;
    }
  //printf("line[%d] = > %c\n", i, line[i]);
  if (line[i] != ' ')
    {
      //printf("b\n");
      return (ERROR);
    }
  i++;
  while (line[i] >= '0' && line[i] <= '9')
    {
      //printf("line[%d] = > %c\n", i, line[i]);
      i++;
    }
  //printf("line[%d] = > %d\n", i, line[i]);
  if (line[i] != '\0')
    {
      //printf("c\n");
      return (ERROR);
    }
  return (SUCCESS);
}

int		valid_link(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0' && line[i] != '-')
    i++;
  if (line[i] != '-')
    return (ERROR);
  return (SUCCESS);
}
