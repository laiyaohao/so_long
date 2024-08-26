#include "so_long.h"

int count_items(char **map, char item)
{
  int i;
  int j;
  int count;

  i = 0;
  count = 0;
  while (map[i] != NULL)
  {
    j = 0;
    while (map[i][j] != '\0')
    {
      if (map[i][j] == item)
      {
        count++;
      }
      j++;
    }
    i++;
  }
  return (count);
}