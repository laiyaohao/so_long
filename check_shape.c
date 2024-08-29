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

int	check_shape(char **map)
{
  int line;
  int cols;
  int i;

  line = 0;
  cols = sl_strlen(map[0]);
  while (map[line] != NULL)
  {
    i = 0;
    if (map[line][0] != '1')
      return (0);
    while (map[line][i] != '\0')
    {
      if (((line == 0 || map[line + 1] == NULL) &&
          map[line][i] != '1') ||
          (map[line][i + 1] == '\0' && map[line][i] != '1')
         )
        return (0);
      i++;
    }
    if (i != cols)
      return (0);
    line++;
  }
  if (line < 3)
    return (0);
  return (1);
}