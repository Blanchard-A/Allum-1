/*
** ai.c for allum1 in /home/blanch_p/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 15:41:41 2016 Alexandre Blanchard
** Last update Sat Feb 20 10:39:47 2016 Alexandre Blanchard
*/

#include "allum.h"

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
  xor->somme_matches = (xor->line_1 + xor->line_2 + xor->line_3 + xor->line_4);
  xor->somme = (xor->line_1 ^ xor->line_2 ^ xor->line_3 ^ xor->line_4) ^ 1;
  xor->l_1 = xor->line_1 ^ xor->somme;
  xor->l_2 = xor->line_2 ^ xor->somme;
  xor->l_3 = xor->line_3 ^ xor->somme;
  xor->l_4 = xor->line_4 ^ xor->somme;

  printf("line 1 = %i\n", xor->line_1);
  printf("line 2 = %i\n", xor->line_2);
  printf("line 3 = %i\n", xor->line_3);
  printf("line 4 = %i\n", xor->line_4);
  printf("somme_matches = %i\n", xor->somme_matches);
  printf("somme = %i\n", xor->somme);
  printf("l_1 = %i\n", xor->l_1);
  printf("l_2 = %i\n", xor->l_2);
  printf("l_3 = %i\n", xor->l_3);
  printf("l_4 = %i\n", xor->l_4);
  /* printf("lin_enl = %i\n", xor->line_enl); */
  /* printf("matches = %i\n", xor->matches); */
  /* printf("line = %i\n", xor->line); */


}

void	who(t_xor *xor)
{
  printf("ok\n");
  if (xor->line_1 != 0 && xor->line_1 >= xor->l_1)
    {
      printf("1\n");
      xor->line_enl = xor->l_1;
      xor->matches = xor->l_1;
    }
  if (xor->l_2 <= xor->matches && xor->line_2 != 0 && xor->line_2 >= xor->l_2)
    {
      printf("2\n");
      xor->line_enl = 2;
      xor->matches = xor->l_2;
    }
  if (xor->l_3 <= xor->matches && xor->line_3 != 0 && xor->line_3 >= xor->l_3)
    {
      printf("3\n");
      xor->line_enl = 3;
      xor->matches = xor->l_3;
    }
  if (xor->l_4 <= xor->matches  && xor->line_4 != 0 && xor->line_4 >= xor->l_4)
    {
      printf("4\n");
      xor->line_enl = 4;
      xor->matches = xor->l_4;
    }
}

void	rando(t_xor *xor, char **all)
{
  srand(time(0) * getpid());
  xor->line = rand() % 4 + 1;
  while (check_ia_line(xor->line, all) == -1)
    {
      xor->line = rand() % 4 + 1;
    }
  xor->matches = rand() % 7 + 1;
  while (check_ia_matches(xor->matches, xor->line, all) == -1)
    {
      xor->matches = rand() % 7 + 1;
    }
  /* all = change_tab_1(xor->line, xor->matches, all, 0); */
  /* return (all); */
}

char	**tab_ia_hard(char **all)
{
  t_xor	xor;
  int	test;

  value(&xor, all);
  xor.line_enl = 4;
  xor.matches = 7;
  /* xor.line = 4; */
  who(&xor);

  /* printf("line 1 = %i\n", xor.line_1); */
  /* printf("line 2 = %i\n", xor.line_2); */
  /* printf("line 3 = %i\n", xor.line_3); */
  /* printf("line 4 = %i\n", xor.line_4); */
  /* /\* printf("somme_matches = %i\n", xor.somme_matches); *\/ */
  /* printf("somme = %i\n", xor.somme); */
  /* printf("l_1 = %i\n", xor.l_1); */
  /* printf("l_2 = %i\n", xor.l_2); */
  /* printf("l_3 = %i\n", xor.l_3); */
  /* printf("l_4 = %i\n", xor.l_4); */
  printf("lin_enl = %i\n", xor.line_enl);
  printf("matches = %i\n", xor.matches);
  printf("line = %i\n", xor.line);

  test = check_ia_matches(xor.matches, xor.line_enl, all);
  if (test == -1)
    {
      printf("\n\n\n[[[[[[]]]]]]\n\n\n");
      rando(&xor, all);
    }
  printf("test = %i\n", test);
  if (xor.matches == 0)
    all = change_tab2(xor.line_enl, recup_nb_allum(all, xor.line_enl), all, 0);
  else
    all = change_tab2(xor.line_enl, xor.matches, all, 0);
  return (all);
}
