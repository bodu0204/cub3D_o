/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:43:22 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 09:46:26 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100

typedef enum e_direction
{
	VERTICAL,
	HORIZONTAL
}	t_direction;

typedef enum e_block
{
	BLOCK,
	SPACE,
	NONE,
	MAP_ERROR,
	FREE_MAP = 0xff
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

#endif
