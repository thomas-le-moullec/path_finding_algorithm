/*
** disp.c for disp in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/mylib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 15:42:57 2016 Thomas LE MOULLEC
** Last update Fri Apr 15 15:10:23 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

void		my_putchar(char c, int output)
{
  write(output, &c, 1);
}

void		my_putstr(char *str, int output)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i], output);
      i++;
    }
}
