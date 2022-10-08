/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:44:58 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/08 23:25:14 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

t_pos	check_horizontal_intersection(t_info *info, double angle)
{
	t_pos	ray;
	double	dy;

	dy = ceil(info->player.y) - info->player.y;
	ray.x = info->player.x + dy / tan(angle);
	ray.y = ceil(info->player.y);
	while (true)
	{
		//printf("(x, y) = (%f, %f)\n", ray.x, ray.y);
		ray.x = ray.x + 1 / tan(angle);
		ray.y = ray.y + 1;
		if (true) //function
			break ;
	}
	return (ray);
}

t_pos	check_vertical_intersection(t_info *info, double angle)
{
	t_pos	ray;
	double	dx;

	dx = ceil(info->player.x) - info->player.x;
	ray.x = ceil(info->player.x);
	ray.y = info->player.y + dx * tan(angle);
	while (true)
	{
		ray.x = ray.x + 1;
		ray.y = ray.y + tan(angle);
		if (true) //function
			break ;
	}
	return (ray);
}

double	calculate_distance(t_pos player, t_pos wall)
{
	double	distance;

	distance = sqrt(pow(wall.x - player.x, 2) + pow(wall.y - player.y, 2));
	return (distance);
}

t_pos	check_intersection(t_info *info, double angle)
{
	t_pos	horizontal_intersection;
	t_pos	vertical_intersection;

	horizontal_intersection = check_horizontal_intersection(info, angle);
	//printf("(x, y) = (%f, %f)\n", horizontal_intersection.x, horizontal_intersection.y);
	vertical_intersection = check_vertical_intersection(info, angle);
	if (fabs(horizontal_intersection.x - info->player.x)
		< fabs(vertical_intersection.x - info->player.x))
		return (horizontal_intersection);
	else
		return (vertical_intersection);
}

int	main(void)
{
	t_info	info;

	info.player.x = 4.3;
	info.player.y = 4.3;
	check_intersection(&info, get_radian_from_degree(145));
	//check_horizontal_intersection(&info, get_radian_from_degree(170));
	//check_vertical_intersection(&info, get_radian_from_degree(40));
}
