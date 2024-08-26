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

// int count_lines(char *line, int *fd)
// {
//   int num;
//   int cols;
//   int i;
//   int err;
//   int collectable;

//   num = 0;
//   err = 0;
//   collectable = 0;
//   cols = sl_strlen(line);
	
//   while (line != NULL)
//   {
//     num++;
//     i = sl_strlen(line);
//     collectable += count_collectables(line);
//     if (cols != i)
//       err = 1;
//     line = get_next_line(*fd);
//   }
//   if (err == 1 || collectable == 0)
//     return (err);
//   return (num);
// }

int	check_shape_wall(char **map)
{
  // char  *line;
  // int   line_num;
  // int   error;
  // int   num_of_lines;

  // line = get_next_line(*fd);
  // line[0] = '\0';
  // line_num = 0;
  // error = 0;
  // num_of_lines = count_lines(line, fd);
  // close(*fd);
  // if (num_of_lines < 3)
  //   return (0);
  // line = get_next_line(*fd);
  // error = check_line(line, line_num, num_of_lines, fd);
  // close(*fd);
  // if (error)
  //   return (0);

  int num_of_lines;
  int cols;
  int i;

  num_of_lines = 0;
  cols = sl_strlen(map[0]);
  while (map[num_of_lines] != NULL)
  {
    i = 0;
    if (map[num_of_lines][0] != '1')
      return (0);
    while (map[num_of_lines][i] != '\0')
    {
      if (((num_of_lines == 0 || map[num_of_lines + 1] == NULL) &&
          map[num_of_lines][i] != '1') ||
          (map[num_of_lines][i + 1] == '\0' && map[num_of_lines][i] != '1')
         )
        return (0);
      i++;
    }
    if (i != cols)
      return (0);
    num_of_lines++;
  }
  if (num_of_lines < 3)
    return (0);
  return (1);
}