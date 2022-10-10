/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:08:28 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 15:18:53 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/plot.h"

void	plot_col(t_info *info, size_t col, t_intersection *intersec, double height)
{
	ssize_t			i;
	ssize_t			wall_top;
	ssize_t			wall_bottom;
	unsigned int	data[BL];

	i = 0;
	img(data, intersec->wall_direction, intersec->img_col, NULL);
	wall_top = DIS_Y * (BL - height) / (BL * 2);
	wall_bottom = DIS_Y - wall_top;
	
	while (i < DIS_Y)
	{
		if (wall_top <= i && i <= wall_bottom)
			my_pixel_put(info, col, i, data[(int)((BL - 1) * (double)(i - wall_top) / (wall_bottom - wall_top))]);
		else if (i < wall_top)
			my_pixel_put(info, col, i,flooring(0));
		else
			my_pixel_put(info, col, i, ceiling(0));
		i++;
	}
}

void	plot_screen(t_info *info)
{
	size_t			i;
	t_intersection	intersec;
	double			angle;
	double			height;

	i = 0;
	while (i < DIS_X)
	{
		angle = info->direction + ((double)i - DIS_X / 2) / DIS_X * SIGHT;
		intersec = check_intersection(info, convert_to_radian(angle));
		height = BL / (2 * intersec.distance * tan(convert_to_radian(SIGHT / 2)));
		plot_col(info, i, &intersec, height);
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.address, 0, 0);
}
