/*
** my_get_nbr2.c for my_get_nbr2.c in /home/le-mou_t/rendu/Ex
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Oct 15 14:27:19 2015 Thomas LE MOULLEC
** Last update Thu Apr 14 15:42:18 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int	my_get_nbr(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        return (ERROR);
      while (str[i] >= '0' && str[i] <= '9')
	{
	  nb = (nb + str[i] - '0') * 10;
	  i++;
	}
    }
  return (nb / 10);
}
