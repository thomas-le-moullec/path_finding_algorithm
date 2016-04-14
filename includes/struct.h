/*
** struct.h for struct in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 10:32:03 2016 leo LE DIOURON
** Last update Thu Apr 14 10:36:35 2016 leo LE DIOURON
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_maillon
{
  int			id;
  char			*name;
  int			nb_pipe;
  int			*id_pipe;
}			t_maillon;

typedef struct		s_path
{
  int			pos; /*la position correspond a l'ID du maillon*/
  int			*paths;
  t_path		next; /*liste (doublement ?) chainée des paths*/
  t_path		prec;
}			t_path;

#endif
