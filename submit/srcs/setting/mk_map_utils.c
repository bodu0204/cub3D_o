/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:57 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/11 19:05:13 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setting.h"

int	check_map_char(char *file)
{
	int	h;

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

int	check_map_shape(unsigned char	*map, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < x * y)
	{
		if (map[i] == SPACE \
		&& (!(i / x) || !(i % x) || i / x == y - 1 || i % x == x - 1 \
			|| map[i + 1] == NONE || map[i - 1] == NONE \
			|| map[i + x] == NONE || map[i - x] == NONE))
			return (1);
		i++;
	}
	return (0);
}
