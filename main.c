/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:05 by ylai              #+#    #+#             */
/*   Updated: 2024/08/31 17:03:10 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_play(t_data *data, int keycode, int x, int y)
{
	if (keycode == 65361 && data->map[y][x - 1] != '1')
	{
		if (x - 1 == data->exit_x && y == data->exit_y && data->collectables == 0)
			exit(0);
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
	if (keycode == 65363 && data->map[y][x + 1] != '1')
	{
		if (x + 1 == data->exit_x && y == data->exit_y && data->collectables == 0)
			exit(0);
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
	if (keycode == 65362 && data->map[y - 1][x] != '1')
	{
		if (x == data->exit_x && y - 1 == data->exit_y && data->collectables == 0)
			exit(0);
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
	if (keycode == 65364 && data->map[y + 1][x] != '1')
	{
		if (x == data->exit_x && y + 1 == data->exit_y && data->collectables == 0)
			exit(0);
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	int	x;
	int	y;

	// int	ex;
	// int	ey;
	x = find_item(data->map, 'P', 'x');
	y = find_item(data->map, 'P', 'y');
	// ex = find_item(data->map, 'E', 'x');
	// ey = find_item(data->map, 'E', 'y');
	printf("keycode: %d\n", keycode);
	// if (keycode == 65361)  // Left arrow
	// {
	// 	if (data->map[y][x - 1] != '1')
	// 	{
	// 		data->map[y][x - 1] = 'P';
	// 		data->map[y][x] = '0';
	// 	}
	// 	move_play(data, x, y);
	// }
	// if (keycode == 65363)  // Right arrow
	// 	data->play_x += 1;
	// if (keycode == 65362)  // Up arrow
	// 	data->play_y -= 1;
	// if (keycode == 65364)  // Down arrow
	// 	data->play_y += 1;
	printf("x: %d\ny: %d\n", x, y);
	move_play(data, keycode, x, y);
	render_map(data);
	// render_play(data->mlx, data->window, data->player, data->play_x,
	// data->play_y);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	// t_images	images;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map>\n", argv[0]);
		return (1);
	}

	data.map = copy_map(argv[1]);
	// check if the map is valid
	if (!check_shape(data.map) || !check_map_con(data.map)	
		|| !check_path(argv[1]))
	{
		fprintf(stderr, "Invalid map\n");
		return (1);
	}
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, cal_x(data.map), cal_y(argv[1]),
			"so_long");
	data.images.coll_img = load_image(data.mlx, "textures/collectable.xpm");
	data.images.wall_img = load_image(data.mlx, "textures/wall.xpm");
	data.images.play_img = load_image(data.mlx, "textures/player.xpm");
	data.images.exit_img = load_image(data.mlx, "textures/exit.xpm");
	data.moves = 0;
	data.exit_x = find_item(data.map, 'E', 'x');
	data.exit_y = find_item(data.map, 'E', 'y');
	// then we render the map
	render_map(&data);

	mlx_key_hook(data.window, handle_keypress, &data);
	mlx_hook(data.window, 17, 0, close_window_click, NULL);

	// minimize the window
	mlx_do_sync(data.mlx);

	// mlx_string_put(mlx, window, 300,300, 0x00FF0000,"habfsanf");
	// Enter the MiniLibX loop
	// mlx_loop waits for events like mouse clicks, key presses
	// so after this function, i cannot draw on the window anymore
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.window);

	free_map(data.map);
	data.map = NULL;

	return (0);
}