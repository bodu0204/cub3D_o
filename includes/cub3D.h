/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:51:10 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/08 17:51:22 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# define BL 30
# define DIS_X 180
# define DIS_Y 300
typedef struct s_info
{
    
}	t_info;
typedef struct s_vector
{
    
}	t_vector;
typedef struct s_camera
{
	double	coordinate_x;
	double	coordinate_y;
	double	coordinate_z;
	double	vector_x;
	double	vector_y;
	double	vector_z;
	double	zoom;
	double	time;
	char	flag[8];
}	t_camera;
int		input_str(char *s);
int		linear_algebra(double	*algebra, double	*solution, int	x, int	y);
double	time_diff(void);
#endif
