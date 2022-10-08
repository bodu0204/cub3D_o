/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:41:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/08 21:26:12 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/map.h"

int	map(size_t x, size_t y, char *file)
{
	static unsigned char	*cube_map;
	static size_t			X;
	static size_t			Y;

	if (file)
		cube_map = mk_map(file, &X, &Y);
	else if (file == (char *)FREE_MAP)
		free(cube_map);
	if (X < x || Y < y || !cube_map)
		return (MAP_ERROR);
	return (cube_map[(y * X) + x]);
}

unsigned char	*mk_map(char *filename, size_t *x, size_t *y)
{
	unsigned char	*r;
	char			*f;

	f = read_file(filename);
	if (!f)
		return (NULL);
	if (search_map())
	{
		free(f);
		return (NULL);
	}
	set_map_size(f, x, y);
		;
	return (r);
}