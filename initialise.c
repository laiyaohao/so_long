/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:11:31 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 14:12:48 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (mlx_loop_end(data->mlx));
	return (0);
}

void	destroy_map(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->images.wall_img);
	mlx_destroy_image(data->mlx, data->images.coll_img);
	mlx_destroy_image(data->mlx, data->images.exit_img);
	mlx_destroy_image(data->mlx, data->images.play_img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
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
	mlx_hook(data->window, 17, 0, close_window_click, data);
	mlx_do_sync(data->mlx);
	mlx_loop(data->mlx);
	destroy_map(data);
}
