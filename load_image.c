/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:21:47 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 13:36:27 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_image(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	return (img);
}
