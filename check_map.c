#include "so_long.h"

int count_collectables(char *str)
{
  int i;
  int coll;

  i = 0;
  coll = 0;
  while (str[i] != '\n')
  {
    if (str[i] == 'C')
    {
      coll++;
    }
    i++;
  }
  return (coll);
}

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
  int collectable;

  num = 0;
  err = 0;
  collectable = 0;
  cols = sl_strlen(line);
  while (line != '\0')
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
  error = 0;
  num_of_lines = count_lines(line, &fd);
  close(fd);
  if (num_of_lines < 3)
    return (0);
  fd = open(map, O_RDONLY);
  if (fd < 0)
    return (0);
  line = get_next_line(fd);
  error = check_line(line, line_num, num_of_lines, &fd);
  close(fd);
  if (error)
    return (0);
  return (1);
}