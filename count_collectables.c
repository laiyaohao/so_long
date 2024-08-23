#include "so_long.h"

int count_collectables(char **map)
{
  int i;
  int j;
  int collectables;

  i = 0;
  while (map[i] != NULL)
  {
    j = 0;
    while (map[i][j] != '\0')
    {
      if (map[i][j] == 'C')
      {
        collectables++;
      }
      j++;
    }
    i++;
  }
  return (collectables);
}