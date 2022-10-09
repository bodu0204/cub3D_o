#include	"../../../includes/cub3D.h"
#include	"../../../includes/structure.h"
#include	"../../../libft/libft.h"
unsigned char *mk_map(char *file, size_t *x, size_t *y);

int map(size_t x, size_t y, char *file)
{
	static unsigned char	*cube_map;
	static size_t			X;
	static size_t			Y;

	if (file)
		cube_map = mk_map(file, &X, &Y);
	else if (file == (char *)FREE_MAP)
		free(cube_map);
	if (x >= X || y >= Y || !cube_map)
		return (MAP_ERROR);
	return (cube_map[(y * X) + x]);
}
