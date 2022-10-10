/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:57 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 22:19:46 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/setting.h"

#include "debug.h"

unsigned char *mk_map(char *file, size_t *x, size_t *y)
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

int	check_map_char(char *file)
{
	int h;

	h = 0;
	while (*file \
	&& (*file == ' ' || *file == '1' || *file == '0' \
		|| *file == '\n' || *file == 'N' || *file == 'S' \
		|| *file == 'E' || *file == 'W'))
	{
		if (*file == 'N' || *file == 'S' || *file == 'E' || *file == 'W')
		{
			if (h)
				return (1);
			else
				h = 1;
		}
		file++;
	}
	if (*file)
		return (1);
	return (0);
}

int set_map_size(char *file, size_t *x, size_t *y)
{
	size_t l;

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
	size_t l;

	while (*file)
	{
		l = 0;
		while (file[l]  && file[l] != '\n')
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

int check_map_shape(unsigned char	*map, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < x * y)
	{
		if (map[i] == SPACE \
		&& (!(i / x) || !(i % x) || i / x == y - 1 || i % x == x - 1 \
			|| map[i + 1] == NONE || map[i - 1] == NONE \
			|| map[i + x] == NONE || map[i - x] == NONE ))
			return (1);
		i++;
	}
	return (0);
}


