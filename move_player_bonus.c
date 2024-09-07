/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:37:06 by ylai              #+#    #+#             */
/*   Updated: 2024/09/07 14:37:07 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data, int keycode, int x, int y)
{
	if (keycode == 65361 && data->map[y][x - 1] != '1')
	{
		if (x - 1 == data->exit_x && y == data->exit_y
			&& data->collectables == 0)
		{
			mlx_loop_end(data->mlx);
			return ;
		}
		if (data->map[y][x - 1] == 'C')
			data->collectables--;
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		data->moves++;
	}
}

void	move_right(t_data *data, int keycode, int x, int y)
{
	if (keycode == 65363 && data->map[y][x + 1] != '1')
	{
		if (x + 1 == data->exit_x && y == data->exit_y
			&& data->collectables == 0)
		{
			mlx_loop_end(data->mlx);
			return ;
		}
		if (data->map[y][x + 1] == 'C')
			data->collectables--;
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		data->moves++;
	}
}

void	move_up(t_data *data, int keycode, int x, int y)
{
	if (keycode == 65362 && data->map[y - 1][x] != '1')
	{
		if (x == data->exit_x && y - 1 == data->exit_y
			&& data->collectables == 0)
		{
			mlx_loop_end(data->mlx);
			return ;
		}
		if (data->map[y - 1][x] == 'C')
			data->collectables--;
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		data->moves++;
	}
}

void	move_down(t_data *data, int keycode, int x, int y)
{
	if (keycode == 65364 && data->map[y + 1][x] != '1')
	{
		if (x == data->exit_x && y + 1 == data->exit_y
			&& data->collectables == 0)
		{
			mlx_loop_end(data->mlx);
			return ;
		}
		if (data->map[y + 1][x] == 'C')
			data->collectables--;
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		data->moves++;
	}
}

void	move_player_bonus(t_data *data, int keycode, int x, int y)
{
	move_left(data, keycode, x, y);
	move_right(data, keycode, x, y);
	move_up(data, keycode, x, y);
	move_down(data, keycode, x, y);
}
