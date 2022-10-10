/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:55:56 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 22:15:15 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/global.h"

int	img(unsigned int *dest, t_direction d, size_t col, void *img_data)
{
	static unsigned int	imgs[4 * BL * BL];
	size_t				i;
	size_t				b;

	if (img_data && mk_img(img_data, imgs + (d * BL * BL)))
		return (1);
	i = 0;
	b = (d * BL * BL) + (col * BL);
	if (dest)
	{
		while (i < BL)
		{
			dest[i] = imgs[b + i];
			i++;
		}
	}
	return (0);
}
