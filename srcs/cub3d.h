#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx.h"

# define BL 30
# define DIS_X 1200
# define DIS_Y 900

# define ESC_KEY 65307
# define TL_KEY 65361
# define TR_KEY 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define GO_LEN   0.01
# define TRN_LEN  0.01

# define GO_      0x0f
# define TRN_     0xf0

# define GO_F     0x01
# define GO_B     0x02
# define GO_L     0x03
# define GO_R     0x04
# define GO_NONE  0x05

# define TRN_L    0x10
# define TRN_R    0x20
# define TRN_NONE 0x30

# define FERR_ALL ~0LU
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

typedef struct s_now
{
    double  x;
    double  y;
    double  r;
}t_now;

//global


void	*mlx(void *set);
void	*win(void *set);
unsigned 	key(unsigned set);
t_now 	now(t_now *set);
void 	img(int flag, size_t len, void *io);
void 	map(size_t x, size_t y, void *set);

int		set_key(int	key, void	*p);
int		rm_key(int	key, void	*p);

int		end_cub(void	*p);
int		cub3d(void	*p);

#endif 
