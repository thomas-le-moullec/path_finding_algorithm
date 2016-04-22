/*
** struct.h for struct in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 10:32:03 2016 leo LE DIOURON
** Last update Fri Apr 22 14:15:30 2016 Thomas LE MOULLEC
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define ERROR		-1
#define FATAL_ERROR	-2
#define SUCCESS		0

#define EMPTY		0
#define FULL		1
#define START		2
#define END		3

#define READ_SIZE      	30000000
#define DOUBLE_COM	0
#define SIMPLE_COM      1
#define LINKS      	2
#define NODES      	3

#define BEGIN           0
#define CURRENT         1
#define FINISH          2

typedef struct          s_ant
{
  int                   pos_path;
  int                   num_path;
  int                   flag;
}                       t_ant;

typedef struct		s_parser
{
  char			*buffer;
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
  int			*id_pipe;
  int			cmpt;
}			t_maillon;

typedef struct		s_path
{
  int			cmpt;
  int			pos;
  int			*history;
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
  int			start;
}			t_infos;

typedef struct		s_data
{
  t_parser              parser;
  t_maillon             *nodes;
  t_path                *path;
  int                   **best_paths;
  t_infos               infos;
  t_ant                 *ant;
  int                   (*fct[4])(int *, char *, struct s_data *);
}			t_data;

#endif
