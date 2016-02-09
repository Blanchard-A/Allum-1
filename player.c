/*
** aff_game.c for allum in /home/blanch_p/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 11:54:51 2016 Alexandre Blanchard
** Last update Tue Feb  9 12:53:23 2016 Alexandre Blanchard
*/

#include "allum.h"

int	who_plays()
{
  static int	turn = 0;

  if ((turn % 2) == 0)
    {
      my_printf("Your turn:\n");
    }
  else if ((turn % 2) == 1)
    {
      my_printf("AI's turn...\n");
    }
  turn++;
  return (turn);
}

char	**player(char **all)
{
  char	*s;
  int	line;
  int	matches;

  my_printf("Line: ");
  s = get_next_line(0);
  line = verif_line(my_getnbr(s), all);
  if (line != 0)
    {
      my_printf("Matches: ");
      s = get_next_line(0);
      matches = verif_matches(my_getnbr(s), line, all);
    }
  if (matches != 0)
    all = change_tab(line, matches, all, 1);
  return (all);
}
