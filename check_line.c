#include "so_long.h"

void  check_walls(char pixel, int line_num, int num_of_lines, int *error)
{
  if (line_num == 0 && pixel != '1')
    *error = 1;
  if (line_num == num_of_lines && pixel != '1')
    *error = 1;
}

void check_error(char pixel, int *map_exit, int *map_start, int *error, int *collect)
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
  if (pixel == 'C')
    *collect++;
}

int check_line(char *line, int line_num, int num_of_lines)
{
  int i;
  int map_exit;
  int map_start;
  int error;
  int collect;

  error = 0;
  if (line[0] != '1')
    return (1);
  i = 1;
  collect = 0;
  map_exit = 0;
  map_start = 0;
  while (line[i] != '\n')
  {
    check_walls(line[i], line_num, num_of_lines, &error);
    if (line[i] == 'C' || line[i] == 'E' || line[i] == 'P'
      || line[i] == '1' || line[i] == '0')
    {
      check_error(line[i], &map_exit, &map_start, &error, &collect);
      i++;
    } 
  }
  return (0);
}