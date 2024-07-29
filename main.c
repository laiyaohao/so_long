/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:05 by ylai              #+#    #+#             */
/*   Updated: 2024/07/30 00:31:11 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*window;

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
	return 0;
}