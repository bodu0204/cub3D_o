#include "../cub3d.h"
void dis(size_t x, size_t y, unsigned c, int f)
{
	static void *img_p;
	static unsigned *p;
	static int size_line;
	static int bits_per_pixel;

	if (f == CLOR)
		p[y * size_line + x * (bits_per_pixel / 8)] = c;
	else if (f == SET)
	{
		img_p = mlx_new_image(mlx(0), DIS_W, DIS_H);
		p = mlx_get_data_addr(img_p, &bits_per_pixel, &size_line, &f);
	}
	else if (f == FLUSH)
		mlx_put_image_to_window(mlx(0), win(0), img_p, x, y);
	else if (f == (int) FREE_ALL)
	return ;
}