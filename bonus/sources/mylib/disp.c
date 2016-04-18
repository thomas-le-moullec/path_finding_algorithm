/*
** disp.c for disp in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/mylib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 15:42:57 2016 Thomas LE MOULLEC
** Last update Mon Apr 18 18:08:48 2016 Thomas LE MOULLEC
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

void		my_putstr_buffer(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n' && str[i + 1] == '\0')
	i++;
      else
	{
	  my_putchar(str[i], 1);
	  i++;
	}
    }
}
