#ifndef CLB_3D_H
# define CLB_3D_H

#include <stdlib.h>
#include <fcntl.h>

# define BL 30
# define DIS_X 180
# define DIS_Y 300

enum
{
	BLOCK, 
	SPACE, 
	NONE, 
	MAP_ERROR, 
	FREE_MAP = 0xff
};

int map(size_t, size_t, char *);

#endif
