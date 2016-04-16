/*
** my_strcmp.c for my_strcmp in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 16:45:37 2016 Thomas LE MOULLEC
** Last update Sat Apr 16 15:28:00 2016 leo LE DIOURON
*/

#include "lem_in.h"

int		my_strcmp(char *str, char *src)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == src[i])
	i++;
      else
	return (ERROR);
    }
  if (str[i] != src[i])
    return (ERROR);
  return (SUCCESS);
}
