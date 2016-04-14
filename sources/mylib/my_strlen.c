/*
** my_strlen.c for my_strlen in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/parser
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 17:47:06 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 17:47:38 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
