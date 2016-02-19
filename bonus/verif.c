/*
** verif.c for allum in /home/blanch_p/Prog_elem/CPE_2015_Allum1/new
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Feb  9 09:47:37 2016 Alexandre Blanchard
** Last update Fri Feb 19 13:19:44 2016 Alexandre Blanchard
*/

#include "allum.h"

int	check_empty(int nombre, char **all, int line)
{
  int	i;

  i = 0;
  nombre = 0;
  while (all[line][i])
    {
      if (all[line][i] == '|')
	nombre++;
      i++;
    }
  return (nombre);
}

int	verif_line_1(int nb, char **all)
{
  int	nombre;

  nombre = 0;
  if (nb == 0 || nb > 4)
    {
      my_printf("Error: this line is out of range\n");
      player_1(all);
      return (0);
    }
  else if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      player_1(all);
      return (0);
    }
  else
    nombre = check_empty(nombre, all, nb);
  if (nombre == 0)
    {
      my_printf("Error: this line is empty\n");
      player_1(all);
      return (0);
    }
  return (nb);
}

int	verif_line_2(int nb, char **all)
{
  int	nombre;

  nombre = 0;
  if (nb == 0 || nb > 4)
    {
      my_printf("Error: this line is out of range\n");
      player_2(all);
      return (0);
    }
  else if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      player_2(all);
      return (0);
    }
  else
    nombre = check_empty(nombre, all, nb);
  if (nombre == 0)
    {
      my_printf("Error: this line is empty\n");
      player_2(all);
      return (0);
    }
  return (nb);
}


int	verif_matches_1(int nb, int line, char **all)
{
  int	matches;

  matches = 0;
  if (nb == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      player_1(all);
      return (0);
    }
  else if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      player_1(all);
      return (0);
    }
  else
    matches = check_empty(matches, all, line);
  if (matches < nb)
    {
      my_printf("Error: not enough match(es) on this line\n");
      player_1(all);
      return (0);
    }
  return (nb);
}

int	verif_matches_2(int nb, int line, char **all)
{
  int	matches;

  matches = 0;
  if (nb == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      player_2(all);
      return (0);
    }
  else if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      player_2(all);
      return (0);
    }
  else
    matches = check_empty(matches, all, line);
  if (matches < nb)
    {
      my_printf("Error: not enough match(es) on this line\n");
      player_2(all);
      return (0);
    }
  return (nb);
}


char	**change_tab_1(int line, int matches, char **all, int player)
{
  int	i;
  int	nb;

  nb = 0;
  i = 7;
  while (nb < matches)
    {
      while (all[line][i] != '|')
         i--;
      all[line][i] = ' ';
      i--;
       nb++;
    }
  if (player == 1)
    my_printf("Player removed %i match(es) from line %i\n", matches, line);
  else if (player == 0)
    my_printf("AI removed %i match(es) from line %i\n", matches, line);
  aff_double_tab_easy(all);
  return (all);
}

char	**change_tab2(int line, int matches, char **all, int player)
{
  int	i;
  int	nb;

  nb = 0;
  i = 7;
  while (nb < matches)
    {
      while (all[line][i] != '|')
         i--;
      all[line][i] = ' ';
      i--;
       nb++;
    }
  if (player == 1)
    my_printf("Player removed %i match(es) from line %i\n", matches, line);
  else if (player == 0)
    my_printf("AI removed %i match(es) from line %i\n", matches, line);
  aff_double_tab_hard(all);
  return (all);
}

int	how_many_matches(char **all)
{
  int	nb;
  int	i;
  int	j;

  j = 0;
  nb = 0;
  while (all[j] != NULL)
    {
      i = 0;
      while (all[j][i] != '\0')
	{
	  if (all[j][i] == '|')
	    nb++;
	  i++;
	}
      j++;
    }
  return (nb);
}

int	verif_win(char **all, int player)
{
  int	nb;

  nb = 0;
  nb = how_many_matches(all);
  if (nb == 0 && player == 0)
    {
      my_printf("I lost.. snif.. but I'll get you next time!!\n");
      return (1);
    }
  if (nb == 0 && player == 1)
    {
      my_printf("You lost, too bad..\n");
      return (1);
    }
  return (0);
}
