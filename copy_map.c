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

char	**place_char(char **map, int num_of_lines, char *line, int fd)
{
	int i;

	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			map[num_of_lines][i] = line[i];
			i++;
		}
		map[num_of_lines][i] = '\0';
		num_of_lines++;
		line = get_next_line(fd);
		printf("num_of_lines: %d\n", num_of_lines);
	}
	return (map);
}

char	**copy_map(char *map_file_name)
{
	int	num_of_lines;
	char  *line;
	int	fd;
	char	**map;

	fd = open_map(map_file_name);
	line = get_next_line(fd);
	num_of_lines = count_lines(map_file_name);
	map = (char **)malloc((num_of_lines + 1) * sizeof(char *));
	map[num_of_lines] = NULL;
	while (num_of_lines != 0)
	{
		map[num_of_lines - 1] = (char *)malloc((sl_strlen(line) + 1) * sizeof(char));
		num_of_lines--;
	}
	place_char(map, num_of_lines, line, fd);
	close(fd);
	return (map);
}
