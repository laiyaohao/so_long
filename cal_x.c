#include "so_long.h"

int	cal_x(char **map)
{
	int	i;

	i = sl_strlen(map[0]) * TILE_SIZE;
	return (i);
}
