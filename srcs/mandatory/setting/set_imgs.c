/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:13 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 22:21:20 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/setting.h"

#include "debug.h"

int	set_imgs(char *file, t_info *i)
{
	char	*img_n[4];
	void	*img_f[4];

	ft_bzero(img_n, sizeof(img_n));
	ft_bzero(img_f, sizeof(img_f));
	if (set_img_fname(img_n, file) \
	|| set_imgf(img_n, img_f, i))
		return (1);
	restore_file(img_n);
	img(NULL, NORTH, 0, img_f[NORTH]);
	img(NULL, SOUTH, 0, img_f[SOUTH]);
	img(NULL, EAST, 0, img_f[EAST]);
	img(NULL, WEST, 0, img_f[WEST]);
	rm_imgs(img_f, i);
	return (0);
}

int	set_img_fname(char *img_n[], char *file)
{
	unsigned int	fc;
	size_t			i;

	fc = 0;
	while (*file)
	{
		if (!ft_memcmp(file, "NO ", 3) \
		|| !ft_memcmp(file, "SO ", 3) \
		|| !ft_memcmp(file, "WE ", 3) \
		|| !ft_memcmp(file, "EA ", 3))
			i = set_img_elm(img_n, file);
		else if (!ft_memcmp(file, "F ", 2)
		|| !ft_memcmp(file, "C ", 2))
			i = set_fc_elm(file, &fc);
		else if(*file == '\n')
			i = 1;
		else
			break ;
		if (!i)
			return (1);
		file += i;
	}
	return (0);
}

size_t	set_img_elm(char *img_n[], char *file)
{
	size_t	set;
	size_t	i;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
		return (0);
	file[i] = '\0';
	if (!ft_memcmp(file, "NO ", 3))
			set = NORTH;
	else if(!ft_memcmp(file, "SO ", 3))
			set = SOUTH;
	else if(!ft_memcmp(file, "WE ", 3))
			set = WEST;
	else if(!ft_memcmp(file, "EA ", 3))
			set = EAST;
	else
		return (0);
	if (img_n[set])
		return (0);
	img_n[set] = file + 3;
	return (i + 1);
}

size_t	set_fc_elm(char *file, unsigned int *f)
{
	unsigned int	rgb;
	size_t			i;

	rgb = str_to_rgb(file + 2, f);
	if (*f & 1U << 2)
		return (0);
	if (!ft_memcmp(file, "F ", 2))
	{
		if (*f & 1U)
			return (0);
		*f = 1U;
		flooring(rgb);
	}
	else
	{
		if (*f & 1U << 1)
			return (0);
		*f = 1U << 1;
		ceiling(rgb);
	}
	i = 0;
	while (f[i] && file[i] != '\n')
		i++;
	if (!f[i])
		return (0);
	return (i + 1);
}

unsigned int	str_to_rgb(char * str, unsigned int *f)
{
	unsigned int rgb[3];
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


int set_imgf(char *img_n[], void *img_f[], t_info *i)
{
	size_t	l;
	char	*f;
	int		x;
	int		y;

	l = 0;
	while (l < 4)
	{
		f = is_xpm(img_n[l]);
		if (!f)
		{
			rm_imgs(img_f, i);
			return (1);
		}
		img_f[l] = mlx_xpm_file_to_image(i->mlx, f, &x, &y);
		if (!img_f[l] || x < BL || y < BL)
		{
			rm_imgs(img_f, i);
			return (1);
		}
		l++;
	}
	return(0);
}

void rm_imgs(void *img_f[], t_info *i)
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
	size_t l;

	l = ft_strlen(f);
	if (l < 4 || ft_memcmp(f + l - 4, ".xpm", 4))
		return (NULL);
	while (*f == ' ')
		f++;
	return (f);
}

void	restore_file(char *fname[])
{
	size_t l;

	l = 0;
	while (l < 4)
	{
		fname[l][ft_strlen(fname[l])] = '\n';
		l++;
	}
	return ;
}