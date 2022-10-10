/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:44:58 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:46:42 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

t_pos	find_block_pos(t_pos intersection, double angle, int direction)
{
	t_pos	block;

	if (direction == HORIZONTAL && 0 <= angle && angle < M_PI)
	{
		block.x = floor(intersection.x);
		block.y = round(intersection.y);
	}
	else if (direction == HORIZONTAL && M_PI <= angle && angle < 2 * M_PI)
	{
		block.x = floor(intersection.x);
		block.y = round(intersection.y - 1);
	}
	else if (direction == VERTICAL && ((0 <= angle && angle < M_PI_2)
			|| (3 * M_PI_2 <= angle && angle < 2 * M_PI)))
	{
		block.x = round(intersection.x);
		block.y = floor(intersection.y);
	}
	else
	{
		block.x = round(intersection.x - 1);
		block.y = floor(intersection.y);
	}
	return (block);
}

int	check_block(t_pos intersection, double angle, int direction)
{
	int	block;

	if (intersection.x < 0 || intersection.y < 0)
		return (MAP_ERROR);
	intersection = find_block_pos(intersection, angle, direction);
	block = map(intersection.x, intersection.y, NULL);
	return (block);
}

int	get_sign(double angle, int direction)
{
	if (direction == HORIZONTAL && 0 <= angle && angle < M_PI)
		return (1);
	else if (direction == HORIZONTAL && M_PI <= angle && angle < 2 * M_PI)
		return (-1);
	else if (direction == VERTICAL && ((0 <= angle && angle < M_PI_2)
			|| (3 * M_PI_2 <= angle && angle < 2 * M_PI)))
		return (1);
	else
		return (-1);
}

t_pos	check_horizontal_intersection(t_info *info, double angle)
{
	t_pos	ray;
	double	dy;
	int		block;
	int		sign;

	if (M_PI <= angle && angle < M_PI * 2)
		dy = floor(info->player.y) - info->player.y;
	else
		dy = ceil(info->player.y) - info->player.y;
	sign = get_sign(angle, HORIZONTAL);
	ray.x = info->player.x + dy / tan(angle);
	ray.y = info->player.y + dy;
	while (true)
	{
		block = check_block(ray, angle, HORIZONTAL);
		if (block == BLOCK || block == NONE || block == MAP_ERROR)
			break ;
		ray.x = ray.x + sign * 1 / tan(angle);
		ray.y = ray.y + sign;
	}
	return (ray);
}

t_pos	check_vertical_intersection(t_info *info, double angle)
{
	t_pos	ray;
	double	dx;
	int		block;
	int		sign;

	if (M_PI_2 <= angle && angle < M_PI_2 * 3)
		dx = floor(info->player.x) - info->player.x;
	else
		dx = ceil(info->player.x) - info->player.x;
	sign = get_sign(angle, VERTICAL);
	ray.x = info->player.x + dx;
	ray.y = info->player.y + dx * tan(angle);
	while (true)
	{
		block = check_block(ray, angle, VERTICAL);
		if (block == BLOCK || block == NONE || block == MAP_ERROR)
			break ;
		ray.x = ray.x + sign;
		ray.y = ray.y + sign * tan(angle);
	}
	return (ray);
}

void	input_data(t_intersection *intersec, double angle, int direction, t_pos pos)
{
	if (direction == HORIZONTAL && 0 <= angle && angle < M_PI)
	{
		intersec->wall_direction = NORTH;
		intersec->img_col = (floor(pos.x + 1) - pos.x) * (BL - 1);
	}
	else if (direction == HORIZONTAL && M_PI <= angle && angle < 2 * M_PI)
	{
		intersec->wall_direction = SOUTH;
		intersec->img_col = (pos.x - floor(pos.x)) * (BL - 1);
	}
	else if (direction == VERTICAL && ((0 <= angle && angle < M_PI_2)
			|| (3 * M_PI_2 <= angle && angle < 2 * M_PI)))
	{
		intersec->wall_direction = WEST;
		intersec->img_col = (pos.y - floor(pos.y)) * (BL - 1);
	}
	else
	{
		intersec->wall_direction = EAST;
		intersec->img_col = (floor(pos.y + 1) - pos.y) * (BL - 1);
	}
}

t_intersection	check_intersection(t_info *info, double angle)
{
	t_intersection	intersec;
	t_pos			hori_intersec;
	t_pos			vert_intersec;

	hori_intersec = check_horizontal_intersection(info, angle);
	vert_intersec = check_vertical_intersection(info, angle);
	if (fabs(hori_intersec.x - info->player.x)
		< fabs(vert_intersec.x - info->player.x))
	{
		intersec.distance = calculate_distance(info, hori_intersec);
		intersec.wall = hori_intersec;
		input_data(&intersec, angle, HORIZONTAL, hori_intersec);
	}
	else
	{
		intersec.distance = calculate_distance(info, vert_intersec);
		intersec.wall = vert_intersec;
		input_data(&intersec, angle, VERTICAL, vert_intersec);
	}
	return (intersec);
}
