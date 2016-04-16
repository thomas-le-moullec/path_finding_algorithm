/*
** generator.c for generator in /home/tchikl_h/rendu/B2/CPE/test
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Apr 15 20:19:27 2016 Hervé TCHIKLADZE
** Last update Sat Apr 16 10:23:59 2016 Hervé TCHIKLADZE
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int		main(int ac, char **av)
{
  int		nb_ant;
  int		nb_room;
  int		tmp;
  int		i;
  int		j;

  i = 1;
  srand(time(NULL));
  if (ac == 3 && atoi(av[1]) != 0 && atoi(av[2]) != 0)
    {
      nb_ant = rand() % atoi(av[1]);
      nb_room = rand() % atoi(av[2]);
      printf("%d\n##start\n0 1 1\n##end\n", nb_ant);
      printf("%d 1 1\n", nb_room);
      while (i < nb_room)
	printf("%d 1 1\n", i++);
      i = 0;
      while (i < nb_room)
	{
	  j = 0;
	  tmp = rand() % nb_room / 2;
	  while (j < tmp)
	    {
	      printf("%d-%d\n", i, rand() % nb_room);
	      j++;
	    }
	  i++;
	}
      exit(0);
    }
  exit(-1);
}
