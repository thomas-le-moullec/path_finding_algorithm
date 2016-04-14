/*
** struct.h for struct in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 10:32:03 2016 leo LE DIOURON
** Last update Thu Apr 14 23:44:10 2016 Thomas LE MOULLEC
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define ERROR		-1
#define SUCCESS		0

#define EMPTY		0
#define FULL		1
#define START		2
#define END		3

#define READ_SIZE      	1000000
#define DOUBLE_COM	0
#define SIMPLE_COM      1
#define LINKS      	2
#define NODES      	3

typedef struct		s_parser
{
  char			buffer[READ_SIZE];
  int			nbr_start;
  int			nbr_end;
  int			nbr_line;
}			t_parser;

typedef struct		s_maillon
{
  int			flag;
  int			id;
  char			*name;
  int			nb_pipe;
  char			**id_pipe;
  int			cmpt;
}			t_maillon;

typedef struct		s_path
{
  int			value;
  int			pos;
  int			*paths;
  struct s_path		*next;
  struct s_path		*prev;
}			t_path;

typedef struct		s_infos
{
  int			ret;
  int			j;
  int			nbr_ants;
  int			nbr_nodes;
  int			nbr_links;
  char			**tubes;
}			t_infos;

typedef struct		s_data
{
  t_parser		parser;
  t_maillon		*nodes;
  t_path		*path;
  t_infos		infos;
  int			(*fct[4])(int *, char *, struct s_data *);
}			t_data;

#endif
