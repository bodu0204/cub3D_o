/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:06:31 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:41:50 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/plot.h"

void	my_pixel_put(t_info *info, int x, int y, unsigned int color)
{
	void	*dst;

	dst = info->img.data + (y * info->img.size_l + x * (info->img.bpp / 8));
	*(unsigned int *)dst = color;
}
