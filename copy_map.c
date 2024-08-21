/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:43:59 by ylai              #+#    #+#             */
/*   Updated: 2024/08/21 21:26:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(int *fd)
{
	int	num_of_lines;
	char  *line;
	int	cols;
	char	**map;
	int	i;

	line = get_next_line(*fd);
	cols = sl_strlen(line);
	num_of_lines = count_lines(line, &fd);
	map = (char **)malloc(num_of_lines * sizeof(char *));
	i = 0;
	while (i < num_of_lines)
	{
		map[i] = (char *)malloc(cols * sizeof(char));
		i++;
	}
	
	return (map);
}