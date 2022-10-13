/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imgs_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:13 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/11 19:05:31 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setting.h"

unsigned int	str_to_rgb(char *str, unsigned int *f)
{
	unsigned int	rgb[3];
	size_t			i;

	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(*str))
			*f |= 1u << 2;
		rgb[i] = ft_atoi(str);
		if (rgb[i] > 0xff)
			*f |= 1u << 2;
		while (*str && ft_isdigit(*str))
			str++;
		i++;
		if ((i < 3 && *str != ',') || (i == 3 && *str != '\n'))
			*f |= 1u << 2;
		str++;
	}
	return (0xff000000 + (rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

void	rm_imgs(void *img_f[], t_info *i)
{
	size_t	l;

	l = 0;
	while (l < 4)
	{
		if (img_f[l])
			mlx_destroy_image(i->mlx, img_f[l]);
		img_f[l] = NULL;
		l++;
	}
	return ;
}

char	*is_xpm(char *f)
{
	size_t	l;

	l = ft_strlen(f);
	if (l < 4 || ft_memcmp(f + l - 4, ".xpm", 4))
		return (NULL);
	while (*f == ' ')
		f++;
	return (f);
}

void	restore_file(char *fname[])
{
	size_t	l;

	l = 0;
	while (l < 4)
	{
		fname[l][ft_strlen(fname[l])] = '\n';
		l++;
	}
	return ;
}
