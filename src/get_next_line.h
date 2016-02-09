/*
** get_next_line.h for get_next_line in /home/blanch_p/test/get_next
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Jan 12 13:30:36 2016 Alexandre Blanchard
** Last update Mon Feb  8 12:10:29 2016 Alexandre Blanchard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef READ_SIZE
# define READ_SIZE (1)

#endif /* READ_SIZE */

typedef struct s_arg
{
  char          *buf;
  int           i;
  char          *str;
  int           nb_read;
  int           incr;
  int		ret;
  int		size;
}		t_arg;

char    *get_next_line(const int);


#endif /* GET_NEXT_LINE_H_ */
