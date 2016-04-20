##
## Makefile for Makefile in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
## 
## Made by leo LE DIOURON
## Login   <le-dio_l@epitech.net>
## 
## Started on  Thu Apr 14 10:22:07 2016 leo LE DIOURON
## Last update Wed Apr 20 11:20:10 2016 leo LE DIOURON
##

NAME		=	lem_in

CC		=	gcc -g

RM		=	rm -f

LIB             =       -L/home/${USER}/.froot/lib/             \
                        -llapin                                 \
                        -L/usr/local/lib                        \
                        -lsfml-audio                            \
                        -lsfml-graphics                         \
                        -lsfml-window                           \
                        -lsfml-system                           \
                        -lstdc++ -ldl                           \
                        -lm                                     \

MAIN		=	./sources/main/

ERRORS		=	./sources/errors/

PARSER		=	./sources/parser/

ALGO		=	./sources/algo/

MY_LIB		=	./sources/mylib/

GRAPH           =       ./sources/graphic/

SRCS		=	$(MAIN)main.c			\
			$(ERRORS)error_args.c		\
			$(ERRORS)error_default.c	\
			$(ERRORS)error_act.c		\
			$(ERRORS)error_nbr.c		\
			$(PARSER)parser.c		\
			$(PARSER)check_buffer.c		\
			$(PARSER)valid.c		\
			$(PARSER)fill_id.c		\
			$(PARSER)fill_links.c		\
			$(PARSER)fill_nbr.c		\
			$(PARSER)db_com.c		\
			$(PARSER)links_fct.c		\
			$(PARSER)init.c			\
			$(PARSER)functions.c		\
			$(ALGO)algo_path.c		\
			$(ALGO)algo_ant.c		\
			$(ALGO)list.c			\
                        $(GRAPH)graphic.c               \
			$(GRAPH)noise_color.c           \
                        $(GRAPH)tekpixel.c              \
			$(GRAPH)graphic_second.c        \
			$(GRAPH)graphic_third.c        \
                        $(GRAPH)tekcircle.c             \
			$(MY_LIB)disp.c			\
			$(MY_LIB)my_strcmp.c		\
			$(MY_LIB)my_epur_str.c		\
			$(MY_LIB)my_get_nbr.c		\
			$(MY_LIB)my_put_nbr.c		\
			$(MY_LIB)my_strlen.c		\
			$(MY_LIB)my_free.c		\
			$(MY_LIB)my_strcpy.c		\

OBJS		=	$(SRCS:.c=.o)

IFLAGS		=	-I ./includes/

CFLAGS		=	-W -Wall -Wextra $(LIB) $(IFLAGS)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

