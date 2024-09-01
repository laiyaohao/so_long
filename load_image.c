#include "so_long.h"

void	*load_image(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	return (img);
}
