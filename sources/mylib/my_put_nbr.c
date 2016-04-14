/*
** my_put_nbr.c for my_put_nbr.c in /home/le-mou_t/rendu/Ex
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Oct  1 09:32:47 2015 Thomas LE MOULLEC
** Last update Thu Apr 14 15:42:50 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

void		my_put_nbr(int nb)
{
  int		x;

  x = 1;
  if (nb < 0)
    my_putchar('-');
  else
    nb = -nb;
  while (nb / x < -9)
    x = x * 10;
  while (x)
    {
      my_putchar(-(nb / x) + '0');
      nb = nb % x;
      x = x / 10;
    }
}
