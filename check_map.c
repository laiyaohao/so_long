#include "so_long.h"

int sl_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\n')
    i++;
  return (i);
}

int count_lines(char *line, int *fd)
{
  int num;
  int cols;
  int i;
  int err;

  num = 0;
  err = 0;
  cols = sl_strlen(line);
  while (line != '\0')
  {
    num++;
    i = sl_strlen(line);
    if (cols != i)
      err = 1;
    line = get_next_line(*fd);
  }
  if (err == 1)
    return (err);
  return (num);
}

int	check_map(char *map)
{
  int		fd;
  char  *line;
  int   line_num;
  int   error;
  int   num_of_lines;

  fd = open(map, O_RDONLY);
  if (fd < 0)
    return (0);
  line = get_next_line(fd);
  printf("%s\n", line);
  line_num = 0;
  /**
   * line[i] == 'C' || line[i] == 'E' || line[i] == 'P' || line[i] == '1'
          || line[i] == '0' || line[i] == '\n'
   */
  error = 0;
  num_of_lines = count_lines(line, &fd);
  if (num_of_lines < 3)
    return (0);
  close(fd);
  fd = open(map, O_RDONLY);
  if (fd < 0)
    return (0);
  line = get_next_line(fd);
  while (line != '\0')
  {
    error = check_line(line, line_num, num_of_lines);
    if (error)
      break;
    line = get_next_line(fd);
    line_num++;
  }
  if (error)
    return (0);
  return (1);
}