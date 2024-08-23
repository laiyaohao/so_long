#include "so_long.h"

int count_lines(char *map_file_name)
{
  int fd;
  char  *line;
  int num;

  fd = open_map(map_file_name);
  num = 0;
  line = get_next_line(fd);
  while (line != NULL)
  {
    num++;
    line = get_next_line(fd);
  }
  close(fd);
  return (num);
}