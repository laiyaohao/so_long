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

int	check_path(char *map)
{
	/**
	 * flood fill algorithm
	 */
	int		fd;
	int		num_of_lines;
	char  *line;

	fd = open_file(map);
	line = get_next_line(fd);
	num_of_lines = count_lines(line, &fd);

	// find location of the player first
	
}