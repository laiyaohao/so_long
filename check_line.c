/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:32:52 by ylai              #+#    #+#             */
/*   Updated: 2024/08/20 19:09:20 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  check_walls(char pixel, int line_num, int num_of_lines, int *error)
{
	printf("line_num: %d\n", line_num);
	printf("num_of_lines: %d\n", num_of_lines);
  if (line_num == 0 && pixel != '1')
    *error = 1;
  if (line_num == num_of_lines && pixel != '1')
    *error = 1;
}

void check_error(char pixel, int *map_exit, int *map_start, int *error)
{
	if (pixel == 'C' || pixel == 'E' || pixel == 'P'
        || pixel == '1' || pixel == '0')
	{
		if (pixel == 'E')
		{
			if (*map_exit == 1)
				*error = 1;
			else
				*map_exit = 1;
		}
		if (pixel == 'P')
		{
			if (*map_start == 1)
				*error = 1;
			else
				*map_start = 1;
		}
	}
	else
		*error = 1;
}

int check_line(char *line, int line_num, int num_of_lines, int *fd)
{
  int i;
  int map_exit;
  int map_start;
  int error;

  error = 0;
  map_exit = 0;
  map_start = 0;
  while (line != NULL)
  {
		i = 0;
		line_num++;
    while (line[i] != '\n' && line[i] != '\0')
    {
			if (line[0] != '1')
    		error = 1;
      check_walls(line[i], line_num, num_of_lines, &error);
      check_error(line[i], &map_exit, &map_start, &error);
			i++;
    }
    line = get_next_line(*fd);
  }
  if (error)
		return (1);
  return (0);
}