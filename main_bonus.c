/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:36:56 by ylai              #+#    #+#             */
/*   Updated: 2024/09/07 14:36:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map>\n", argv[0]);
		return (1);
	}
	data.map = copy_map(argv[1]);
	if (!check_shape(data.map) || !check_map_con(data.map)
		|| !check_path(argv[1]))
	{
		free_map(data.map);
		data.map = NULL;
		ft_printf("Error\nInvalid map\n");
		return (1);
	}
	initialise_bonus(&data, argv);
	free_map(data.map);
	data.map = NULL;
	return (0);
}
