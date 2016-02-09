##
## Makefile for Makefile in /home/blanch_p/rendu/PSU_2015_my_printf
## 
## Made by Alexandre Blanchard
## Login   <blanch_p@epitech.net>
## 
## Started on  Wed Nov 11 18:01:44 2015 Alexandre Blanchard
## Last update Tue Feb  9 11:42:54 2016 Alexandre Blanchard
##

NAME		=	allum1

SRC		=	allum.c \
			player.c \
			tab.c \
			ia.c \
			verif.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -ansi -pedantic #-Werror

LDFLAGS		=	-I./include

.c.o:
			gcc -c $< -o $@ $(LDFLAGS) $(CFLAGS)

all:			$(NAME)

$(NAME):		$(OBJ)	
			gcc $(OBJ) -lmy -L. -o $(NAME) -g

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all