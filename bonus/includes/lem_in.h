/*
** lem_in.h for lem_in in /home/le-mou_t/rendu/CPE_2015_Lemin
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun Apr 17 18:54:16 2016 Thomas LE MOULLEC
** Last update Wed Apr 20 10:48:17 2016 Thomas CHABOT
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "lapin.h"
#include "struct.h"

int             fill_links(t_data *);
int             fill_tubes(t_data *);
int             loop_tubes(t_data *, int *, int, int);
int             count_line(t_data *, int);

int             fill_id_pipe(t_data *, int);
int             my_cut_id(t_data *, int);
int             my_cut_other(t_data *, int);
int             my_strcmp_colon(char *, char *);
int             my_strcmp_other(char *, char *);

void            free_nodes(t_data *);

int             valid_node(char *);

char            *copy_line(t_data *, int *);
int             find_type(t_data *, char *);
int             check_line(t_data *, int *);
int             check_buffer(t_data *);

int             init_infos(t_data *);
int             init_functions(t_data *);
int             init_parser(t_data *);
int             init_nodes(t_data *);
void            init_id_pipe(t_data *, int);

int             take_parser(t_data *);
int             end_parser(t_data *);
int             parser(int, t_data *);

int             fill_nbr_ants(t_data *, char *);
int             fill_nbr_nodes(t_data *);

char            *find_name(char *);
int             double_com_fct(int *, char *, t_data *);
int             my_start(int *, t_data *);
int             my_end(int *, t_data *);

char            *links_cpy(int *, char *);
int             static_ptr(t_data *, int *);
int             links_cmp(t_data *, char *, char *, char *);
char            *other_cpy(int *, char *, int);

int             simple_com_fct(int *, char *, t_data *);
int             links_fct(int *, char *, t_data *);
int             nodes_fct(int *, char *, t_data *);

int		error_default(char *);

int             error_nbr_nodes();
int             error_nbr_ants();

int             error_malloc();
int             error_copying(t_data *);
int             error_reading();
int             error_args();

int             error_link(char *, t_data *);
int             error_correspondance(char *, t_data *);
int             error_node(t_data *, char *);
int             error_simple_com(t_data *, char *);
int             error_type(t_data *, char *);

int		algo_loop(t_data *, int, int, int);
int		algo(t_data *, int, int);
int		find_best_path(t_data *, int);
int		flag_nodes_path(t_data *, int *, int);
int		check_history(int *, int);

int		algo_ant(t_data *);
int		move_ants(t_data *, int);
int		fill_ant(t_data *);

int             creat_list(t_data *);
void            delete_elem(t_path **);
int             cpy_elem(t_path **, int);

int                     main_loop(t_data *);
int                     graphic(t_data *);
t_bunny_response        loop(void *);
t_bunny_response        echap_down(t_bunny_event_state, t_bunny_keysym, void *);
int                     init_win(t_data *);
int                    draw_nodes(t_data *);
int                     draw_links(t_data *);

void                    noise_color_full(t_bunny_pixelarray  *);

void                    tekpixel(t_bunny_pixelarray *, t_bunny_position, unsigned int);
void                    tekpixel2(t_bunny_pixelarray *, t_bunny_position, unsigned int);

int                    tekline(t_bunny_pixelarray *, t_bunny_position *, t_data *, unsigned int);
void                    tekline_vertical(t_bunny_pixelarray *, t_bunny_position *, unsigned int);
void                    tekline_swap(t_bunny_pixelarray *, t_bunny_position *, unsigned int);
t_bunny_position        *swap(t_bunny_position *);

void                    tekcircle(t_bunny_pixelarray *, t_bunny_position, unsigned int, int);

char		*my_strcpy_ptr(char *, char *, int);
char            *my_strcpy_colon(char *, char *);

int             my_strlen(char *);

void		my_putchar(char, int);
void		my_putstr(char *, int);
void            my_putstr_buffer(char *);

int             char_epur(char, char);
char            *my_epur_str(char *);

int		my_get_nbr(char *);

void            my_put_nbr(int, int);

void            my_free(void *);

int		my_strcmp(char *, char *);

#endif
