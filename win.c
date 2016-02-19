/*
** win.c for allum1 in /home/blanch_p/rendu/Semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Feb 19 14:55:01 2016 Alexandre Blanchard
** Last update Fri Feb 19 14:56:16 2016 Alexandre Blanchard
*/

#include "allum.h"

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
