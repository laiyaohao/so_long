#include "so_long.h"

int	count_lines(char *map_file_name)
{
	char	*line;
	int		fd;
	int		num;

	fd = open_map(map_file_name);
	num = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		num++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
	return (num);
}
