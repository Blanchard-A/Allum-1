/*
** aff_game.c for allum in /home/blanch_p/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 11:54:51 2016 Alexandre Blanchard
** Last update Sat Feb 20 18:07:30 2016 Alexandre Blanchard
*/

#include "allum.h"

int	check_good_entry(char *s, char **all)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if ((s[i] < 48 || s[i] > 57))
	{
	  my_printf("Error: invalid input (positive number expected)\n");
	  player_1(all);
	  return (0);
	}
      i++;
    }
  if (i == 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      player_1(all);
      return (0);
    }
  else
    return (1);
}

int	check_good_entry_2(char *s, char **all)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if ((s[i] < 48 || s[i] > 57))
	{
	  my_printf("Error: invalid input (positive number expected)\n");
	  player_2(all);
	  return (0);
	}
      i++;
    }
  if (i == 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      player_2(all);
      return (0);
    }
  else
    return (1);
}


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

char	**player_1(char **all)
{
  char	*s;
  int	line;
  int	matches;
  int	check_line;
  int	check_mat;

  my_printf("Line: ");
  if ((s = get_next_line(0)) == NULL)
    return (NULL);
  check_line = check_good_entry(s, all);
  if (check_line != 0)
    line = verif_line_1(my_getnbr(s), all);
  if (line != 0)
    {
      my_printf("Matches: ");
      if ((s = get_next_line(0)) == NULL)
	return (NULL);
      check_mat = check_good_entry(s, all);
      if (check_mat != 0)
	matches = verif_matches_1(my_getnbr(s), line, all);
    }
  if (matches != 0 && check_mat != 0 && line != 0)
    all = change_tab_1(line, matches, all, 1);
  return (all);
}

char	**player_2(char **all)
{
  char	*s;
  int	line;
  int	matches;
  int	check_line;
  int	check_mat;

  my_printf("Line: ");
  if ((s = get_next_line(0)) == NULL)
    return (NULL);
  check_line = check_good_entry_2(s, all);
  if (check_line != 0)
    line = verif_line_2(my_getnbr(s), all);
  if (line != 0)
    {
      my_printf("Matches: ");
      if ((s = get_next_line(0)) == NULL)
	return (NULL);
      check_mat = check_good_entry_2(s, all);
      if (check_mat != 0)
	matches = verif_matches_2(my_getnbr(s), line, all);
    }
  if (matches != 0 && check_mat != 0 && line != 0)
    all = change_tab2(line, matches, all, 1);
  return (all);
}
