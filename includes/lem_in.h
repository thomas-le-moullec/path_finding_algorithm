/*
** lem_in.h for lemin in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 10:29:16 2016 leo LE DIOURON
** Last update Fri Apr 15 14:54:00 2016 Thomas LE MOULLEC
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

/******************PARSER*******************/

/*fill_links*/
int		fill_links(t_data *);
int		fill_tubes(t_data *);
int		count_line(t_data *, int);

/*fill_id*/
int		fill_id_pipe(t_data *, int);
int             my_cut_id(t_data *, int);
int             my_strcmp_colon(char *, char *);

/*main.c*/
void		free_nodes(t_data *);

/*valid*/
int             valid_node(char *);
int		valid_link(char *);

/*check_buffer.c*/
char            *copy_line(t_data *, int *);
int             find_type(t_data *, char *);
int             check_line(t_data *, int *);
int             check_buffer(t_data *);

/*init*/
int             init_infos(t_data *);
int             init_functions(t_data *);
int             init_parser(t_data *);
int             init_nodes(t_data *);
void            init_id_pipe(t_data *, int);

/*parser.c*/
int             take_parser(t_data *);
int             parser(int, t_data *);

/*fill_nbr*/
int             fill_nbr_ants(t_data *, char *);
int             fill_nbr_nodes(t_data *);

/*db_com.c*/
char            *find_name(char *);
int             double_com_fct(int *, char *, t_data *);
int		my_start(int *, t_data *);
int		my_end(int *, t_data *);

/*functions.c*/
int             simple_com_fct(int *, char *, t_data *);
int             links_fct(int *, char *, t_data *);
char            *links_cpy(int, char *);
int             nodes_fct(int *, char *, t_data *);

/******************MY_LIB*******************/

/*my_strlen*/
int             my_strlen(char *);

/*disp.c*/
void		my_putchar(char);
void		my_putstr(char *);

/*my_epur_str.c*/
int             char_epur(char, char);
char            *my_epur_str(char *);

/*my_get_nbr.c*/
int		my_get_nbr(char *);

/*my_put_nbr.c*/
void            my_put_nbr(int);

/*my_free.c*/
void            my_free(void *);

/*my_strcmp.c*/
int		my_strcmp(char *, char *);

#endif
