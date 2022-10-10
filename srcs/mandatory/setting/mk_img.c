/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:52:03 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 22:18:41 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/setting.h"

int	mk_img(void *img, unsigned int *dst)
{
	t_img	imgs;
	size_t	x;
	size_t	y;

	imgs.address = img;
	imgs.data = mlx_get_data_addr(imgs.address, &imgs.bpp, &imgs.size_l, &imgs.endian);
	x = 0;
	while (x < BL)
	{
		y = 0;
		while (y < BL)
		{
			*dst = get_pic(&imgs, x, y);
			dst++;
			y++;
		}
		x++;
	}
	return (0);
}

unsigned int	get_pic(t_img *img, size_t x, size_t y)
{
	unsigned int	*img_i;

	img_i = (unsigned int *) \
	(img->data + (y * img->size_l + x * (img->bpp / 8)));
	return (*img_i);
}
