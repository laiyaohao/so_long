/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:17:31 by ylai              #+#    #+#             */
/*   Updated: 2024/08/31 16:53:21 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, image, x
		* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	mlx_clear_window(data->mlx, data->window);
	data->collectables = count_items(data->map, 'C');
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			img = NULL;
			if (x == data->exit_x && y == data->exit_y)
				put_image(data, data->images.exit_img, x, y);
			if (data->map[y][x] == 'C')
				put_image(data, data->images.coll_img, x, y);
			if (data->map[y][x] == '1')
				put_image(data, data->images.wall_img, x, y);
			if (data->map[y][x] == 'P')
				put_image(data, data->images.play_img, x, y);
			if (data->map[y][x] == 'E')
				put_image(data, data->images.exit_img, x, y);
			x++;
		}
		y++;
	}
}
