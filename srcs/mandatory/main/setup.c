/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:09:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:45:52 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/cub3D.h"

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.address);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

void	move_view(t_info *info, int keycode)
{
	if (keycode == LEFT)
		info->direction -= 3;
	else if (keycode == RIGHT)
		info->direction += 3;
	plot_screen(info);
}

static t_pos	calculate_moved_place(t_info *info, int keycode)
{
	t_pos	position;
	double	angle;

	angle = convert_to_radian(info->direction);
	if (keycode == W)
	{
		position.x = info->player.x + 0.1 * cos(angle);
		position.y = info->player.y + 0.1 * sin(angle);
	}
	else if (keycode == S)
	{
		position.x = info->player.x - 0.1 * cos(angle);
		position.y = info->player.y - 0.1 * sin(angle);
	}
	else if (keycode == A)
	{
		position.x = info->player.x + 0.1 * cos(angle - 90);
		position.y = info->player.y + 0.1 * sin(angle - 90);
	}
	else
	{
		position.x = info->player.x - 0.1 * cos(angle - 90);
		position.y = info->player.y - 0.1 * sin(angle - 90);
	}
	return (position);
}

void	move_direction(t_info *info, int keycode)
{
	t_pos	position;
	int		block;

	position = calculate_moved_place(info, keycode);
	block = map(position.x, position.y, NULL);
	if (block == BLOCK || block == NONE || block == MAP_ERROR)
		return ;
	info->player.x = position.x;
	info->player.y = position.y;
	plot_screen(info);
}

int	handle_key_input(int keycode, t_info *info)
{
	if (keycode == ESC)
		close_window(info);
	else if (keycode == LEFT || keycode == RIGHT)
		move_view(info, keycode);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_direction(info, keycode);
	return (0);
}
