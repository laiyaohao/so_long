/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:05 by ylai              #+#    #+#             */
/*   Updated: 2024/08/13 19:49:01 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*window;
	// void	*image;

	mlx = mlx_init();
	if (!mlx)
	{
			fprintf(stderr, "Failed to initialize MiniLibX\n");
			return 1;
	}

	window = mlx_new_window(mlx, 800, 600, "My MiniLibX Window");
	if (!window)
	{
			fprintf(stderr, "Failed to create window\n");
			return 1;
	}	
	// image = mlx_new_image(mlx, 50, 50);
	mlx_string_put(mlx, window, 300,300, 0x00FF0000,"habfsanf");
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
	// Enter the MiniLibX loop
	// mlx_loop waits for events like mouse clicks, key presses
	// so after this function, i cannot draw on the window anymore
	mlx_loop(mlx);

	
	
	
	
	return 0;
}