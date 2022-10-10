/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:57 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/11 02:40:34 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/setting.h"

unsigned char	*mk_map(char *file, size_t *x, size_t *y)
{
	unsigned char	*r;

	file = skip_map(file);
	if (check_map_char(file) || set_map_size(file, x, y))
		return (NULL);
	r = malloc((*x) * (*y));
	if (!r)
	{
		write(STDOUT_FILENO, "malloc error\n", 14);
		return (NULL);
	}
	set_map(r, file, *x);
	if (check_map_shape(r, *x, *y))
	{
		free(r);
		return (NULL);
	}
	return (r);
}

char	*skip_map(char *file)
{
	while (*file)
	{
		if (!ft_memcmp(file, "NO ", 3) \
		|| !ft_memcmp(file, "SO ", 3) \
		|| !ft_memcmp(file, "WE ", 3) \
		|| !ft_memcmp(file, "EA ", 3) \
		|| !ft_memcmp(file, "F ", 2) \
		|| !ft_memcmp(file, "C ", 2) \
		|| *file == '\n')
			while (*file && *file != '\n')
				file++;
		else
			break ;
		if (*file == '\n')
			file++;
	}
	if (!(*file))
		return (NULL);
	return (file);
}

int	set_map_size(char *file, size_t *x, size_t *y)
{
	size_t	l;

	*x = 0;
	*y = 0;
	while (*file)
	{
		l = 0;
		while (file[l] && file[l] != '\n')
			l++;
		if (l > *x)
			*x = l;
		(*y)++;
		file += l + (file[l] == '\n');
	}
	if (!(*x) || !(*y))
		return (1);
	return (0);
}

void	set_map(unsigned char	*map, char *file, size_t x)
{
	size_t	l;

	while (*file)
	{
		l = 0;
		while (file[l] && file[l] != '\n')
		{
			if (file[l] == ' ')
				map[l] = NONE;
			else if (file[l] == '0' || file[l] == 'N' || \
			file[l] == 'S' || file[l] == 'E' || file[l] == 'W')
				map[l] = SPACE;
			else if (file[l] == '1')
				map[l] = BLOCK;
			l++;
		}
		file += l + 1;
		while (l < x)
		{
			map[l] = NONE;
			l++;
		}
		map += l;
	}
	return ;
}
