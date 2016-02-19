/*
** tab.c for allum1 in /home/blanch_p/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb  8 12:11:15 2016 Alexandre Blanchard
** Last update Fri Feb 19 13:26:43 2016 Alexandre Blanchard
*/

#include "allum.h"

char	**create_tab(char **all)
{
  if ((all = malloc_tab(all)) == NULL)
    return (NULL);
  all = rempli_star(all);
  all = rempli_tab(all);
  return (all);
}

char	**rempli_star(char **all)
{
  int	i;
  int	j;

  i = 0;
  while (i < 6)
    {
      j = 0;
      while (j < 9)
	{
	  if (i == 0 || i == 5)
	    all[i][j] = '*';
	  else
	    {
	      if (j == 0 || j == 8)
		all[i][j] = '*';
	      else
		all[i][j] = ' ';
	    }
	  j++;
	}
      all[i][j] = '\0';
      i++;
    }
  all[i] = NULL;
  return (all);
}

char	**rempli_tab(char **all)
{
  int	i;
  int	j;
  int	nb_esp;

  nb_esp = 3;
  i = 1;
  while (i < 5)
    {
      j = 1;
      while (j <= nb_esp)
        j++;
      while (j < 8 - nb_esp)
	{
	  all[i][j] = '|';
	  j++;
	}
      i++;
      nb_esp--;
    }
  return (all);
}

char	**malloc_tab(char **all)
{
  int	i;

  i = 0;
  if ((all = malloc(sizeof(char *) * 7)) == NULL)
    return (NULL);
  while (i < 7)
    {
      if ((all[i] = malloc(sizeof(char) * 10)) == NULL)
	return (NULL);
      i++;
    }
  return (all);
}

int	aff_double_tab_easy(char **all)
{
  int	i;
  int	j;
  
  i = 0;
  printf("easy\n");
  while (all[i] != NULL)
    {
      j = 0;
      if (i == 0 || i == 5)
	my_printf("\033[0;32m%s\033[0m\n", all[i]);
      else
	{
	  while (all[i][j])
	    {
	      if (j == 0 || j == 8)
		my_printf("\033[0;32m%c\033[0m", all[i][j]);
	      else
		my_printf("%c", all[i][j]);
	      j++;
	    }
	  my_printf("\n");
	}
      i++;
    }
  my_printf("\n");
  return (0);
}

int	aff_double_tab_hard(char **all)
{
  int	i;
  int	j;
  
  i = 0;
  while (all[i] != NULL)
    {
      j = 0;
      if (i == 0 || i == 5)
	my_printf("\033[0;31m%s\033[0m\n", all[i]);
      else
	{
	  while (all[i][j])
	    {
	      if (j == 0 || j == 8)
		my_printf("\033[0;31m%c\033[0m", all[i][j]);
	      else
		my_printf("%c", all[i][j]);
	      j++;
	    }
	  my_printf("\n");
	}
      i++;
    }
  my_printf("\n");
  return (0);
}
