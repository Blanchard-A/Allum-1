/*
** allum.c for allum1 in /home/blanch_p/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 10:06:51 2016 Alexandre Blanchard
** Last update Fri Feb 19 15:07:20 2016 Alexandre Blanchard
*/

#include "allum.h"

int	main()
{
  char	**all;
  int	turn;
  int	finish;

  finish = 0;
  all = NULL;
  if ((all = create_tab(all)) == NULL)
    return (-1);
  aff_double_tab(all);
  while (finish == 0)
    {
      turn = who_plays();
      if (turn % 2 == 1)
	if (player(all) == NULL)
	  return (NULL);
      if (turn % 2 == 0)
	tab_ia(all);
      finish = verif_win(all, turn % 2);
    }
  return (0);
}
