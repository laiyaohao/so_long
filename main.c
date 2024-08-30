/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:05 by ylai              #+#    #+#             */
/*   Updated: 2024/08/30 17:32:30 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	render_play(void *mlx, void *window, void *play, int play_x, int play_y)
{
	printf("render_play\n");
	mlx_put_image_to_window(mlx, window, play, play_x * TILE_SIZE, play_y * TILE_SIZE);
}

int handle_keypress(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = find_item(data->map, 'P', 'x');
	y = find_item(data->map, 'P', 'y');
	printf("keycode: %d\n", keycode);
	if (keycode == 65361)  // Left arrow
	{
		if (data->map[y][x - 1] != '1')
			
	}
		data->play_x -= 1;
	if (keycode == 65363)  // Right arrow
		data->play_x += 1;
	if (keycode == 65362)  // Up arrow
		data->play_y -= 1;
	if (keycode == 65364)  // Down arrow
		data->play_y += 1;

  render_play(data->mlx, data->window, data->player, data->play_x, data->play_y);

	return 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_images	images;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map>\n", argv[0]);
		return 1;
	}
	
	data.map = copy_map(argv[1]);
	// check if the map is valid
	if (!check_shape(data.map) || !check_map_con(data.map) || !check_path(argv[1]))
	{
		fprintf(stderr, "Invalid map\n");
		return 1;
	}
	data.mlx = mlx_init();

	// need to determine window size
	// by count the number of lines in the map
	// and multiply it by TILE_SIZE
	// do this to x axis also
	// by counting the number of characters in the line
	// and multiply it by TILE_SIZE
	// using these values, can put in background image to the window
	data.window = mlx_new_window(data.mlx, cal_x(data.map), cal_y(argv[1]), "so_long");
	images.coll_img = load_image(data.mlx, "textiles/collectable.xpm");
	images.wall_img = load_image(data.mlx, "textiles/wall.xpm");
	images.play_img = load_image(data.mlx, "textiles/player.xpm");
	// then we render the map
	render_map(&data, &images);
	// int i = 0;
	// while (i < cal_y(argv[1]))
	// {
	// 	int j = 0;
	// 	while (j < cal_x(map))
	// 	{
	// 		mlx_pixel_put(data.mlx, data.window, j, i, 0x0000FFFFFF);
	// 		j++;
	// 	}
		
	// 	i++;
	// }
	
	data.play_x = find_item(map, 'P', 'x');
	data.play_y = find_item(map, 'P', 'y');
	data.player = load_image(data.mlx, "textiles/player.xpm");
	render_play(data.mlx, data.window, data.player, data.play_x, data.play_y);
	// printf("after render_play\n");

	/**
	 * for some reason only can have only 1 key hook
	 */
	mlx_key_hook(data.window, handle_keypress, &data);
	// mlx_key_hook(data.window, close_window_esc, NULL);
	mlx_hook(data.window, 17, 0, close_window_click, NULL);

	// minimize the window
	mlx_do_sync(data.mlx);

	// mlx_string_put(mlx, window, 300,300, 0x00FF0000,"habfsanf");
	// Enter the MiniLibX loop
	// mlx_loop waits for events like mouse clicks, key presses
	// so after this function, i cannot draw on the window anymore
	mlx_loop(data.mlx);

	
	free_map(map);
	map = NULL;
	
	return 0;
}