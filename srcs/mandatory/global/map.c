#include	"../../../includes/global.h"

int map(size_t x, size_t y, char *file)
{
	static unsigned char	*cube_map;
	static size_t			m_x;
	static size_t			m_y;

	if (file)
		cube_map = mk_map(file, &m_x, &m_y);
	else if (file == FREE_CONTENT)
	{
		free(cube_map);
		return (MAP_ERROR);
	}
	if (x >= m_x || y >= m_y || !cube_map)
		return (MAP_ERROR);
	return (cube_map[(y * m_x) + x]);
}
