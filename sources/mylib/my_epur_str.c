/*
** my_epur_str.c for my_epur_str in /home/le-mou_t/rendu/CPE_2015_Lemin/sources/mylib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Thu Apr 14 16:16:41 2016 Thomas LE MOULLEC
** Last update Thu Apr 14 19:17:30 2016 Thomas LE MOULLEC
*/

#include "lem_in.h"

int		char_epur(char first, char second)
{
  if ((first == ' ' || first == '\t') && \
      (second == ' ' || second == '\0' || second == '\t'))
      return (SUCCESS);
  return (ERROR);
}

char		*my_epur_str(char *stock)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!(str = malloc(sizeof(*str) * (my_strlen(stock) + 1))))
    return (NULL);
  while (stock[i] != '\0')
    {
      str[j] = stock[i];
      if (char_epur(stock[i], stock[i + 1]) == SUCCESS)
	j--;
      i++;
      j++;
    }
  str[j] = '\0';
  my_free(stock);
  return (str);
}
