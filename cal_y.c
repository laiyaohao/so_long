#include "so_long.h"

int	cal_y(char *map_file_name)
{
	int	i;

	i = count_lines(map_file_name);
	return (i * TILE_SIZE);
}
