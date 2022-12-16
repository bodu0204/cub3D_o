#include "../cub3D.h"

void *mlx(void *set)
{
	static void*	mlx_ptr;

	if (set)
		mlx_ptr = set;
	return (mlx_ptr);
}

void *win(void *set)
{
	static void*	win_ptr;

	if (set)
		win_ptr = set;
	return (win_ptr);
}
