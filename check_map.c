/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:33:00 by ylai              #+#    #+#             */
/*   Updated: 2024/08/21 21:12:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_collectables(char *str)
{
  int i;
  int coll;

  i = 0;
  coll = 0;
  while (str[i] != '\n' && str[i] != '\0')
  {
    if (str[i] == 'C')
    {
      coll++;
    }
    i++;
  }
  return (coll);
}

int count_lines(char *line, int *fd)
{
  int num;
  int cols;
  int i;
  int err;
  int collectable;

  num = 0;
  err = 0;
  collectable = 0;
  cols = sl_strlen(line);
	
  while (line != NULL)
  {
    num++;
    i = sl_strlen(line);
    collectable += count_collectables(line);
    if (cols != i)
      err = 1;
    line = get_next_line(*fd);
  }
  if (err == 1 || collectable == 0)
    return (err);
  return (num);
}

int	check_map(int *fd)
{
  char  *line;
  int   line_num;
  int   error;
  int   num_of_lines;

  line = get_next_line(*fd);
  line_num = 0;
  error = 0;
  num_of_lines = count_lines(line, fd);
  close(*fd);
  if (num_of_lines < 3)
    return (0);
  line = get_next_line(*fd);
  error = check_line(line, line_num, num_of_lines, fd);
  close(*fd);
  if (error)
    return (0);
  return (1);
}