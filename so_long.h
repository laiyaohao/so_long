/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:53:16 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 14:04:50 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_images
{
	void		*coll_img;
	void		*wall_img;
	void		*exit_img;
	void		*play_img;
}				t_images;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			moves;
	int			exit_x;
	int			exit_y;
	char		**map;
	t_images	images;
	int			collectables;
}				t_data;

int				ft_printf(const char *str, ...);
int				close_window_click(t_data *data);
int				check_shape(char **map);
char			*get_next_line(int fd);
int				sl_strlen(char *str);
int				count_lines(char *map_file_name);
char			**copy_map(char *map_file_name);
int				check_map_con(char **map);
int				find_item(char **map, char item, char axis);
int				count_items(char **map, char item);
int				check_path(char *map_file_name);
void			free_map(char **map);
void			render_map(t_data *data);
int				cal_x(char **map);
int				cal_y(char *map_file_name);
void			*load_image(void *mlx, char *path);
void			initialise(t_data *data, char **argv);
void			move_player(t_data *data, int keycode, int x, int y);

#endif