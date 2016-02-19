/*
** affich.c for allum1 in /blanch_p/Semestre2/Prog_elem/CPE_2015_Allum1/bonus
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Feb 19 14:48:00 2016 Alexandre Blanchard
** Last update Fri Feb 19 14:49:24 2016 Alexandre Blanchard
*/

#include "allum.h"

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

int	aff_double_tab_easy(char **all)
{
  int	i;
  int	j;

  i = 0;
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
