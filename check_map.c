#include "so_long.h"

int	check_map(char *map)
{
  int		fd;
  int		line;
  int		i;

  fd = open(map, O_RDONLY);
  if (fd < 0)
    return (0);
  line = 0;
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    while (line[i] != '\0')
    {
      if (line[i] == 'C' || line[i] == 'E' || line[i] == 'P' || line[i] == '1'
          || line[i] == '0' || line[i] == '\n')
        i++;
      else
        return (0);
    }
  }
  close(fd);
  return (1);
}