/*
** lem_in.h for lemin in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Apr 14 10:29:16 2016 leo LE DIOURON
** Last update Fri Apr 15 19:15:02 2016 Thomas LE MOULLEC
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
int             loop_tubes(t_data *, int *, int, int);
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
int		static_ptr(t_data *, int *);
int             simple_com_fct(int *, char *, t_data *);
int             links_fct(int *, char *, t_data *);
char            *links_cpy(int, char *);
int             nodes_fct(int *, char *, t_data *);

/******************ERRORS*******************/
int		error_args();
int		error_reading();
int		error_nbr_nodes();
int		error_malloc();
int		error_nbr_ants();
int		error_copying(t_data *);
int		error_link(char *, t_data *);
int		error_correspondance(char *, t_data *);
int		error_node(t_data *, char *);
int             error_simple_com(t_data *, char *);
int             error_type(t_data *, char *);

/******************MY_LIB*******************/

/*my_strcpy*/
char		*my_strcpy_ptr(char *, char *, int);

/*my_strlen*/
int             my_strlen(char *);

/*disp.c*/
void		my_putchar(char, int);
void		my_putstr(char *, int);

/*my_epur_str.c*/
int             char_epur(char, char);
char            *my_epur_str(char *);

/*my_get_nbr.c*/
int		my_get_nbr(char *);

/*my_put_nbr.c*/
void            my_put_nbr(int, int);

/*my_free.c*/
void            my_free(void *);

/*my_strcmp.c*/
int		my_strcmp(char *, char *);

#endif
