/*
** ai.c for allum1 in /home/blanch_p/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 15:41:41 2016 Alexandre Blanchard
** Last update Fri Feb 19 11:32:31 2016 Alexandre Blanchard
*/

#include "allum.h"

/* int	check_ia_line(int line, char **all) */
/* { */
/*   int	i; */
/*   int	nombre; */

/*   i = 0; */
/*   nombre = 0; */
/*   while (all[line][i]) */
/*     { */
/*       if (all[line][i] == '|') */
/* 	nombre++; */
/*       i++; */
/*     } */
/*   if (nombre == 0) */
/*     return (-1); */
/*   return (0); */
/* } */

/* int	check_ia_matches(int matches, int line, char **all) */
/* { */
/*   int	i; */
/*   int	nb; */

/*   nb = 0; */
/*   i = 0; */
/*   while (all[line][i] != '\0') */
/*     { */
/*       if (all[line][i] == '|') */
/* 	nb++; */
/*       i++; */
/*     } */
/*   if (nb < matches) */
/*     return (-1); */
/*   return (0); */
/* } */

int	recup_nb_allum(char **all, int line)
{
  int	i;
  int	nb;
  
  nb = 0;
  i = 0;
  while (all[line][i])
    {
      if (all[line][i] == '|')
	nb++;
      i++;
    }
  return (nb);
}

void	value(t_xor *xor, char **all)
{
  xor->line_1 = recup_nb_allum(all, 1);
  xor->line_2 = recup_nb_allum(all, 2);
  xor->line_3 = recup_nb_allum(all, 3);
  xor->line_4 = recup_nb_allum(all, 4);
  xor->somme = (xor->line_1 ^ xor->line_2 ^ xor->line_3 ^ xor->line_4) ^ 1;

  xor->l_1 = xor->line_1 ^ xor->somme;
  xor->l_2 = xor->line_2 ^ xor->somme;
  xor->l_3 = xor->line_3 ^ xor->somme;
  xor->l_4 = xor->line_4 ^ xor->somme;  
}

void	who(t_xor *xor)
{
  if (xor->line_1 != 0 && xor->line_1 >= xor->l_1)
    {
      xor->line_enl = xor->l_1;
      xor->matches = xor->l_1;
    }

  if (xor->l_2 <= xor->matches && xor->line_2 != 0 && xor->line_2 >= xor->l_2)
    {
      xor->line_enl = 2;
      xor->matches = xor->l_2;
    }

  if (xor->l_3 <= xor->matches && xor->line_3 != 0 && xor->line_3 >= xor->l_3)
    {
      xor->line_enl = 3;
      xor->matches = xor->l_3;
    }

  if (xor->l_4 <= xor->matches  && xor->line_4 != 0 && xor->line_4 >= xor->l_4)
    {
      xor->line_enl = 4;
      xor->matches = xor->l_4;
    }
}

char	**tab_ia(char **all)
{
  t_xor	xor;

  value(&xor, all);
  who(&xor);

  printf("line 1 %i\n", xor.line_1);
  printf("line 2 %i\n", xor.line_2);
  printf("line 3 %i\n", xor.line_3);
  printf("line 4 %i\n", xor.line_4);
  printf("somme %i\n", xor.somme);
  printf("l1 %i\n", xor.l_1);
  printf("l2 %i\n", xor.l_2);
  printf("l3 %i\n", xor.l_3);
  printf("l4 %i\n", xor.l_4);
  printf("line_enl = %i\n", xor.line_enl);
  printf("matches = %i\n", xor.matches);

  if (xor.matches == 0)
    all = change_tab(xor.line_enl, recup_nb_allum(all, xor.line_enl), all, 0);
  else
    all = change_tab(xor.line_enl, xor.matches, all, 0);
}
