/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:09:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/08 21:20:52 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/cub3D.h"

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.address);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

int	handle_key_input(int keycode, t_info *info)
{
	if (keycode == ESC)
		close_window(info);
	else if (keycode == LEFT || keycode == RIGHT)
		;
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		;
	return (0);
}
