##
## Makefile for Makefile in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
## 
## Made by leo LE DIOURON
## Login   <le-dio_l@epitech.net>
## 
## Started on  Thu Apr 14 10:22:07 2016 leo LE DIOURON
## Last update Fri Apr 15 14:52:23 2016 Thomas LE MOULLEC
##

NAME		=	lem_in

CC		=	gcc -g

RM		=	rm -f

MAIN		=	./sources/main/

PARSER		=	./sources/parser/

ALGO		=	./sources/algo/

MY_LIB		=	./sources/mylib/

SRCS		=	$(MAIN)main.c		\
			$(PARSER)parser.c	\
			$(PARSER)check_buffer.c	\
			$(PARSER)valid.c	\
			$(PARSER)fill_id.c	\
			$(PARSER)fill_links.c	\
			$(PARSER)fill_nbr.c	\
			$(PARSER)db_com.c	\
			$(PARSER)init.c		\
			$(PARSER)functions.c	\
			$(ALGO)algo.c		\
			$(MY_LIB)disp.c		\
			$(MY_LIB)my_epur_str.c	\
			$(MY_LIB)my_get_nbr.c	\
			$(MY_LIB)my_put_nbr.c	\
			$(MY_LIB)my_strlen.c	\
			$(MY_LIB)my_free.c	\
			$(MY_LIB)my_strcmp.c	\

OBJS		=	$(SRCS:.c=.o)

IFLAGS		=	-I ./includes/

CFLAGS		=	-W -Wall -Wextra $(IFLAGS)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

