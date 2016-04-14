/*
** disp.c for disp in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/mylib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 15:42:57 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 17:14:48 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
