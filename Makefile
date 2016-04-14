##
## Makefile for Makefile in /home/le-dio_l/Modules/Module_Prog_elem/Lem-in/CPE_2015_Lemin
## 
## Made by leo LE DIOURON
## Login   <le-dio_l@epitech.net>
## 
## Started on  Thu Apr 14 10:22:07 2016 leo LE DIOURON
## Last update Thu Apr 14 11:08:39 2016 leo LE DIOURON
##

NAME		=	lem_in

CC		=	gcc -g

RM		=	rm -f

MAIN		=	./sources/main

PARSER		=	./sources/parser

ALGO		=	./sources/algo

SRCS		=	$(MAIN)main.c		\
			$(PARSER)parser.c	\
			$(ALGO)algo.c		\

OBJS		=	$(SRCS:.c=.o)

IFLAGS		=	-I. ./includes/

CFLAGS		=	-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

