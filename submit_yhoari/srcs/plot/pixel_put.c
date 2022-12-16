/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:06:31 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/11 19:04:33 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/plot.h"

void	my_pixel_put(t_info *info, int x, int y, unsigned int color)
{
	void	*dst;

	dst = info->img.data + (y * info->img.size_l + x * (info->img.bpp / 8));
	*(unsigned int *)dst = color;
}
