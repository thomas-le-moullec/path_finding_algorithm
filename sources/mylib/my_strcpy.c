/*
** my_strcpy.c for my_strcpy in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/mylib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Fri Apr 15 18:01:40 2016 Thomas LE MOULLEC
** Last update Fri Apr 15 19:18:34 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

char		*my_strcpy_ptr(char *src, char *dest, int ptr)
{
  int		x;

  x = 0;
  while (src[ptr] != '\0')
    {
      dest[x] = src[ptr];
      x++;
      ptr++;
    }
  dest[x] = '\0';
  return (dest);
}
