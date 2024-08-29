#include "so_long.h"

void render_wall(void *mlx, void *win, char **map, void *wall_img)
{
	int	x;
	int	y;
	void	*img;
	
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0') {
			img = NULL;
			if (map[y][x] == '1')
				img = wall_img;
			if (img) {
				mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
