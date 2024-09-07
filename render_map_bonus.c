/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:37:21 by ylai              #+#    #+#             */
/*   Updated: 2024/09/07 14:37:22 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, image, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	put_moves(t_data *data, int x, int y)
{
	char	*num_moves;

	num_moves = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->window, 2 * x * TILE_SIZE / 5, y * TILE_SIZE
		+ TILE_SIZE / 2, 0x00FF0000, "moves: ");
	mlx_string_put(data->mlx, data->window, 2 * x * TILE_SIZE / 5 + 50, y
		* TILE_SIZE + TILE_SIZE / 2, 0x00FF0000, num_moves);
	free(num_moves);
	num_moves = NULL;
}

void	render_map_bonus(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->window);
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (x == data->exit_x && y == data->exit_y)
				put_image(data, data->images.exit_img, x, y);
			if (data->map[y][x] == 'C')
				put_image(data, data->images.coll_img, x, y);
			if (data->map[y][x] == '1')
				put_image(data, data->images.wall_img, x, y);
			if (data->map[y][x] == 'P')
				put_image(data, data->images.play_img, x, y);
			x++;
		}
		y++;
	}
	put_moves(data, x, y);
}
