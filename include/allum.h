/*
** allum.h for allum in /home/blanch_p/Prog_elem/CPE_2015_Allum1/include
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 11:49:12 2016 Alexandre Blanchard
** Last update Tue Feb  9 12:05:49 2016 Alexandre Blanchard
*/

#ifndef ALLUM_H_
# define ALLUM_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/printf.h"
#include "../src/get_next_line.h"

char	**rempli_star(char **);
char	**rempli_tab(char **);
char	**malloc_tab(char **);
int	aff_double_tab(char **);
char	**create_tab(char **);
int	aff_game(char **);
char	**change_tab(int, int, char **, int);
int	verif_line(int, char **);
int	check_line(int, int, char **);
int	verif_matches(int, int, char **);
int	check_ia_iline(int, char **);
int	check_ia_matches(int, int, char **);
char	**tab_ia(char **);
int	verif_win(char **, int);
char	**player(char **);
int	who_plays();

int	my_getnbr(char *);

#endif /* ALLUM_H_ */
