/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:05 by ylai              #+#    #+#             */
/*   Updated: 2024/08/21 21:12:05 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include "so_long.h"
// #include <stdlib.h>

// int  close_window_esc(int keycode, void *param)
// {
//   (void) param;
//   if (keycode == 65307)
//     exit(0);
// 	return 0;
// }

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	// int	fd;
	char	**map;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map>\n", argv[0]);
		return 1;
	}
	// fd = open_map(argv[1]);
	
	map = copy_map(argv[1]);
	// check if the map is valid
	if (!check_shape_wall(map) || !check_map_conditions(map) || !check_path(argv[1]))
	{
		printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	printf("%s\n", map[4]);
		fprintf(stderr, "Invalid map\n");
		return 1;
	}
	
	free(map[0]);
	free(map[1]);
	free(map[2]);
	free(map[3]);
	free(map[4]);
	free(map);
	mlx = mlx_init();
	if (!mlx)
	{
			fprintf(stderr, "Failed to initialize MiniLibX\n");
			return 1;
	}

	window = mlx_new_window(mlx, 800, 600, "so_long");
	if (!window)
	{
			fprintf(stderr, "Failed to create window\n");
			return 1;
	}	
	// image = mlx_new_image(mlx, 50, 50);
	mlx_string_put(mlx, window, 300,300, 0x00FF0000,"habfsanf");
	printf("color value: %d\n", mlx_get_color_value(mlx, 0x00FF0000));
	// 0x00 is just the filler
	// then, RRGGBB is the color
	// in above example, FF is for red, 00 is for green, and 00 is for blue
	// FF is 255, 00 is 0, and 00 is 0
	// so above translate to 255, 0, 0 in rgb, which means red.
	
	/*
	int i = 1;
	while (i < 300)
	{
		mlx_pixel_put(mlx, window, i, i, 0x00FF0000);
		i++;
	}

	*/
	// below are hooks that help to close the windows
	// when escape key is pressed
	mlx_key_hook(window, close_window_esc, NULL);
	// when the 'x' button is clicked
	mlx_hook(window, 17, 0, close_window_click, NULL);

	// minimize the window
	mlx_do_sync(mlx);


	// Enter the MiniLibX loop
	// mlx_loop waits for events like mouse clicks, key presses
	// so after this function, i cannot draw on the window anymore
	mlx_loop(mlx);

	
	
	
	
	return 0;
}