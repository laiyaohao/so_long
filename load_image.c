#include "so_long.h"

void	set_transparency(void *img, int color)
{
	int	*data;
	int	w;
	int	h;

	data = (int *)mlx_get_data_addr(img, &w, &h, &w);
	while (h--)
	{
		int	i = w;
		while (i--)
		{
			if (*(data + (w * h) + i) == color)
				*(data + (w * h) + i) = 0x00000000;
		}
	}
}

void *load_image(void *mlx, char *path)
{
	int	img_width;
	int	img_height;
	void	*img;
	
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	return (img);
}
