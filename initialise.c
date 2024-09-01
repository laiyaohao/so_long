#include "so_long.h"

int	handle_keypress(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = find_item(data->map, 'P', 'x');
	y = find_item(data->map, 'P', 'y');
	move_player(data, keycode, x, y);
	render_map(data);
	if (keycode == 65307)
		exit(0);
	return (0);
}

void	initialise(t_data *data, char **argv)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, cal_x(data->map), cal_y(argv[1]),
			"so_long");
	data->images.coll_img = load_image(data->mlx, "textures/collectable.xpm");
	data->images.wall_img = load_image(data->mlx, "textures/wall.xpm");
	data->images.play_img = load_image(data->mlx, "textures/player.xpm");
	data->images.exit_img = load_image(data->mlx, "textures/exit.xpm");
	data->moves = 0;
	data->exit_x = find_item(data->map, 'E', 'x');
	data->exit_y = find_item(data->map, 'E', 'y');
	data->collectables = count_items(data->map, 'C');
	render_map(data);
	mlx_key_hook(data->window, handle_keypress, data);
	mlx_hook(data->window, 17, 0, close_window_click, NULL);
	mlx_do_sync(data->mlx);
	mlx_loop(data->mlx);
}
