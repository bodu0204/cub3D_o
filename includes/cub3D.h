#ifndef CLB_3D_H
# define CLB_3D_H

#include <stdlib.h>

# define BL 30
# define DIS_X 180
# define DIS_Y 300

enum
{
	BLOCK, 
	SPACE, 
	NONE
};

int map(size_t, size_t, char *);

#endif
