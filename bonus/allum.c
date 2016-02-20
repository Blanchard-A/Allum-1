/*
** allum.c for allum1 in /home/blanch_p/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 10:06:51 2016 Alexandre Blanchard
** Last update Sat Feb 20 18:09:15 2016 Alexandre Blanchard
*/

#include "allum.h"

int	choose_hard()
{
  char	**all;
  int	turn;
  int	finish;

  finish = 0;
  all = NULL;
  if ((all = create_tab(all)) == NULL)
    return (-1);
  aff_double_tab_hard(all);
  while (finish == 0)
    {
      turn = who_plays();
      if (turn % 2 == 1)
	if (player_2(all) == NULL)
	  return (-1);
      if (turn % 2 == 0)
	tab_ia_hard(all);
      finish = verif_win(all, turn % 2);
    }
  return (1);
}

int	choose_easy()
{
  char	**all;
  int	turn;
  int	finish;

  finish = 0;
  all = NULL;
  if ((all = create_tab(all)) == NULL)
    return (-1);
  aff_double_tab_easy(all);
  while (finish == 0)
    {
      turn = who_plays();
      if (turn % 2 == 1)
	if (player_1(all) == NULL)
	  return (-1);
      if (turn % 2 == 0)
	tab_ia(all);
      finish = verif_win(all, turn % 2);
    }
  return (1);
}

int	main()
{
  int	finish;
  char	*s;
  int	difficult;

  finish = 0;
  s = malloc(sizeof(char) * 1);
  my_printf("\033[0;32m1 for EASY\033[0m | ");
  my_printf("\033[0;31m2 for HARD\033[0m\nYour choice: ");
  while (finish == 0 || finish == -1)
    {
      if ((s = get_next_line(0)) == NULL)
	return (-1);
      difficult = my_getnbr(s);
      if (difficult == 1)
	finish = choose_easy();
      if (difficult == 2)
	finish = choose_hard();
    }
  return (0);
}
