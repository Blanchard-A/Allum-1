/*
** get_next_line.c for get_next_line in /rendu/GetNextLine/CPE_2015_getnextline
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Jan 17 11:44:42 2016 Alexandre Blanchard
** Last update Fri Feb 19 14:39:59 2016 Alexandre Blanchard
*/

#include "get_next_line.h"

char		*my_realloc(char *str, int size)
{
  char		*tmp;
  int		new_size;

  new_size = size + READ_SIZE;
  tmp = str;
  if ((str = malloc(new_size + 1)) == NULL)
    return (NULL);
  while (size > 0)
    {
      str[size - 1] = tmp[size - 1];
      size--;
    }
  str[new_size] = '\0';
  return (str);
}

int		check(char *buffer, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      if (buffer[i] == '\n')
	{
	  return (1);
	}
      i++;
    }
  return (0);
}

char		*in_tmp(char *tmp, char *buffer, int *incr2, int size)
{
  int		i;

  i = 0;
  while (buffer[i] != '\n' && i < size)
    {
      i++;
    }
  buffer[i] = '\0';
  i++;
  while (buffer[i] != '\0' && i < size)
    {
      tmp[*incr2] = buffer[i];
      (*incr2)++;
      i++;
    }
  tmp[*incr2] = '\0';
  return (buffer);
}

char		*in_buffer(int incr2, char *buffer, char *tmp)
{
  int		i;

  i = 0;
  while (i < incr2)
    {
      buffer[i] = tmp[i];
      i++;
    }
  buffer[i] = '\0';
  return (buffer);
}

char		*get_next_line(const int fd)
{
  static int	incr2 = 0;
  static char	tmp[READ_SIZE];
  t_arg		n;
  int		size;

  if ((n.buf = malloc(READ_SIZE + 1 + incr2)) == NULL)
    return (NULL);
  size = READ_SIZE + incr2;
  n.ret = 0;
  n.buf = in_buffer(incr2, n.buf, tmp);
  incr2 = 0;
  while ((n.ret = read(fd, n.buf + size - READ_SIZE, READ_SIZE)) == READ_SIZE
	 && check(n.buf, size + n.ret) ==  0)
    {
      if ((n.buf = my_realloc(n.buf, size + n.ret)) == NULL)
	return (NULL);
      size = size + n.ret;
    }
  in_tmp(tmp, n.buf, &incr2, size);
  if (n.ret == 0 && size == READ_SIZE)
    return (NULL);
  return (n.buf);
}
