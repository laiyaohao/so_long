#include "so_long.h"

void  free_map(char **map)
{
  int i;

  i = 0;
  while (map[i] != NULL)
  {
    free(map[i]);
    map[i] = NULL;
    i++;
  }
  free(map);
}