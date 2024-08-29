#include "so_long.h"


void render_map(void *mlx, void *win, char **map)
{
	void  *coll_img;
	void  *wall_img;
	
	// (void) map;
	coll_img = load_image(mlx, "textiles/collectable.xpm");
	wall_img = load_image(mlx, "textiles/wall.xpm");
	render_coll(mlx, win, map, coll_img);
	render_wall(mlx, win, map, wall_img);
}
