#include	"../../../includes/global.h"

int map(size_t x, size_t y, char *file)
{
	static unsigned char	*cube_map;
	static size_t			X;
	static size_t			Y;

	if (file)
		cube_map = mk_map(file, &X, &Y);
	else if (file == FREE_CONTENT)
	{
		free(cube_map);
		return (MAP_ERROR);
	}
	if (x >= X || y >= Y || !cube_map)
		return (MAP_ERROR);
	return (cube_map[(y * X) + x]);
}
