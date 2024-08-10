/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:05 by ylai              #+#    #+#             */
/*   Updated: 2024/08/10 18:27:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*image;

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

	// Enter the MiniLibX loop
	mlx_loop(mlx);

	image = mlx_new_image(mlx, 50, 50);
	// int i = 1;
	// while (i < 300)
	// {
	// 	mlx_pixel_put(mlx, window, i, i, 3319890);
	// 	i++;
	// }
	
	return 0;
}