/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:53:16 by ylai              #+#    #+#             */
/*   Updated: 2024/08/21 21:39:47 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int close_window_esc(int keycode, void *param);
int close_window_click(void *param);
int	check_shape_wall(char **map);
char	*get_next_line(int fd);
int	check_line(char *line, int line_num, int num_of_lines, int *fd);
int	open_file(char *map);
int sl_strlen(char *str);
int count_lines(char *map_file_name);
int	open_map(char *map);
char	**copy_map(char *map_file_name);


#endif