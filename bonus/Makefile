##
## Makefile for Makefile in /home/blanch_p/rendu/PSU_2015_my_printf
## 
## Made by Alexandre Blanchard
## Login   <blanch_p@epitech.net>
## 
## Started on  Wed Nov 11 18:01:44 2015 Alexandre Blanchard
## Last update Tue Jun  7 15:31:06 2016 Alexandre Blanchard
##

NAME		=	allum1

SRC		=	src/allum.c \
			src/player.c \
			src/tab.c \
			src/ia_hard.c \
			src/verif_1.c \
			src/verif_2.c \
			src/ia.c \
			src/affich.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -ansi -pedantic -Werror -Iinclude

LDFLAGS		=	-I./include

.c.o:
			gcc -c $< -o $@ $(LDFLAGS) $(CFLAGS)

all:			$(NAME)

$(NAME):		$(OBJ)	
			gcc $(OBJ) -lmy -L. -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all
