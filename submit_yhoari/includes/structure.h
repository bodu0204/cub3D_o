/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:43:22 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 00:20:07 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include	"stdio.h"

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100

# define BL 30
# define DIS_X 1200
# define DIS_Y 900
# define SIGHT 60

# define MINI_MAP 300
# define MINI_MAP_BL 30

# define FREE_CONTENT (void *)0xff

typedef enum e_dimention
{
	VERTICAL,
	HORIZONTAL
}	t_dimention;

typedef enum e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
}	t_direction;

typedef enum e_block
{
	BLOCK,
	SPACE,
	NONE,
	MAP_ERROR,
}	t_block;

typedef struct s_img {
	void	*address;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_pos	player;
	double	direction;
}	t_info;

typedef struct s_intersection
{
	t_pos		wall;
	size_t		img_col;
	t_direction	wall_direction;
	double		distance;
}	t_intersection;

#endif
