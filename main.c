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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map>\n", argv[0]);
		return (1);
	}
	data.map = copy_map(argv[1]);
	if (!check_shape(data.map) || !check_map_con(data.map)
		|| !check_path(argv[1]))
	{
		fprintf(stderr, "Invalid map\n");
		return (1);
	}
	initialise(&data, argv);
	mlx_destroy_window(data.mlx, data.window);
	free_map(data.map);
	data.map = NULL;
	return (0);
}
