/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:39:06 by ylai              #+#    #+#             */
/*   Updated: 2024/08/21 20:24:05 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill(int x, int y, char **map)
{
	// return (1);
	// if (map[y][x] == '1' || map[y][x] == 'C' || map[y][x] == 'E')
	// 	return (0);
	// map[y][x] = '1';
	// if (flood_fill(x - 1, y, map) == 1)
	// 	return (1);
	// if (flood_fill(x + 1, y, map) == 1)
	// 	return (1);
	// if (flood_fill(x, y - 1, map) == 1)
	// 	return (1);
	// if (flood_fill(x, y + 1, map) == 1)
	// 	return (1);
	// return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
	{
		return (0);
	}
	map[y][x] = 'V';
	if (flood_fill(x - 1, y, map) == 1)
		return (1);
	if (flood_fill(x + 1, y, map) == 1)
		return (1);
	if (flood_fill(x, y - 1, map) == 1)
		return (1);
	if (flood_fill(x, y + 1, map) == 1)
		return (1);
	return (0);
}

int	check_path(char *map_file_name)
{
	char	**map;
	int	after_flood_fill;
	int	collectables;
	int	exits;
	
	map = copy_map(map_file_name);
	after_flood_fill = flood_fill(find_item(map, 'P', 'x'),
																find_item(map, 'P', 'y'), map);
	collectables = count_items(map, 'C');
	exits = count_items(map, 'E');
	free_map(map);
	map = NULL;
	if (after_flood_fill == 0 && collectables == 0 && exits == 0)
		return (1);
	return (0);
	// find location of the player first
	
}