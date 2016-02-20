/*
** allum.h for allum in /home/blanch_p/Prog_elem/CPE_2015_Allum1/include
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 11:49:12 2016 Alexandre Blanchard
** Last update Sat Feb 20 10:13:49 2016 Alexandre Blanchard
*/

#ifndef ALLUM_H_
# define ALLUM_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/printf.h"
#include "../src/get_next_line.h"

typedef struct	s_xor
{
  int		line_1;
  int		line_2;
  int		line_3;
  int		line_4;
  int		somme_matches;
  int		somme;
  int		l_1;
  int		l_2;
  int		l_3;
  int		l_4;
  int		line_enl;
  int		matches;
  int		line;
  
}		t_xor;

/*tab.c*/
char	**create_tab(char **);
char	**rempli_star(char **);
char	**rempli_tab(char **);
char	**malloc_tab(char **);
int	aff_double_tab_easy(char **);
int	aff_double_tab_hard(char **);
/*verif.c*/
int	check_empty(int, char **, int);
int	verif_line_1(int, char **);
int	verif_line_2(int, char **);
int	verif_matches_1(int, int, char **);
int	verif_matches_2(int, int, char **);
char	**change_tab_1(int, int, char **, int);
char	**change_tab2(int, int, char **, int);
int	how_many_matches(char **);
int	verif_win(char **, int);

/* int	aff_game(char **); */
/* int	check_line(int, int, char **); */

/*allum.c*/
int	choose_hard();
int	choose_easy();
/*ia.c*/
int	check_ia_line(int, char **);
int	check_ia_matches(int, int, char **);
char	**tab_ia(char **);
/*ia_hard.c*/
int	recup_nb_allum(char **, int);
void	value(t_xor *, char **);
void	who(t_xor *);
char	**tab_ia_hard(char **);
/*player.c*/
int	check_good_entry(char *, char **);
int	check_good_entry_2(char *, char **);
int	who_plays();
char	**player_1(char **);
char	**player_2(char **);

int	my_getnbr(char *);

#endif /* ALLUM_H_ */
