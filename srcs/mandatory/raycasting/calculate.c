/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:31:59 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:15 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

double	convert_to_radian(double degree)
{
	double	radian;

	degree = fmod(degree, 360);
	if (degree < 0)
		degree = fmod(fmod(degree, 360) + 360, 360);
	else if (degree >= 360)
		degree = fmod(degree, 360);
	radian = degree / 360 * 2 * M_PI;
	return (radian);
}

double	calculate_distance(t_info *info, t_pos wall)
{
	double	distance;
	double	direction_rad;

	direction_rad = convert_to_radian(info->direction);
	distance = (wall.x - info->player.x) * cos(direction_rad)
		+ (wall.y - info->player.y) * sin(direction_rad);
	return (distance);
}
