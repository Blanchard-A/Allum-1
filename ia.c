/*
** ai.c for allum1 in /home/blanch_p/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 15:41:41 2016 Alexandre Blanchard
** Last update Tue Feb  9 12:04:47 2016 Alexandre Blanchard
*/

#include "allum.h"

int	check_ia_line(int line, char **all)
{
  int	i;
  int	nombre;

  i = 0;
  nombre = 0;
  while (all[line][i])
    {
      if (all[line][i] == '|')
	nombre++;
      i++;
    }
  if (nombre == 0)
    return (-1);
  return (0);
}

int	check_ia_matches(int matches, int line, char **all)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (all[line][i] != '\0')
    {
      if (all[line][i] == '|')
	nb++;
      i++;
    }
  if (nb < matches)
    return (-1);
  return (0);
}

char	**tab_ia(char **all)
{
  int	line;
  int	matches;

  srand(time(0) * getpid());
  line = rand() % 4 + 1;
  while (check_ia_line(line, all) == -1)
    {
      line = rand() % 4 + 1;
    }
  matches = rand() % 7 + 1;
  while (check_ia_matches(matches, line, all) == -1)
    {
      matches = rand() % 7 + 1;
    }
  all = change_tab(line, matches, all, 0);
  return (all);
}
