/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:49:54 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 12:40:31 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/cub3D.h"

void	init_setup(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, DIS_X, DIS_Y, "cub3D");
	mlx_hook(info->win, ON_DESTROY, 1L << 0, close_window, info);
	mlx_hook(info->win, ON_KEYDOWN, 1L << 0, handle_key_input, info);
	info->img.address = mlx_new_image(info->mlx, DIS_X, DIS_Y);
	info->img.data = mlx_get_data_addr(info->img.address, \
		&info->img.bpp, &info->img.size_l, &info->img.endian);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 2)
	{
		printf("set arg!\n");
		return (0);
	}
	init_setup(&info);
	if (setting(argv[1], &info))
	{
		printf("can't set!\n");
		return (0);
	}
	plot_screen(&info);
	mlx_loop(info.mlx);
	return (0);
}
