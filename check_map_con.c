/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:13:02 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 14:13:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_con(char **map)
{
	int	collectables;
	int	start_count;
	int	exit_count;

	collectables = count_items(map, 'C');
	start_count = count_items(map, 'P');
	exit_count = count_items(map, 'E');
	if (collectables == 0 || start_count != 1 || exit_count != 1)
		return (0);
	return (1);
}
