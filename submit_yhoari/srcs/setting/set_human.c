/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_human.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:47 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/11 19:05:22 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setting.h"

void	set_human(t_info *i, char *mapf)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (*mapf)
	{
		x = 0;
		while (*mapf && *mapf != '\n')
		{
			if (*mapf == 'N' || *mapf == 'S' || *mapf == 'E' || *mapf == 'W')
			{
				i->player.x = (double)x + 0.5;
				i->player.y = (double)y + 0.5;
				i->direction = (double)((*mapf == 'E') * 0 \
				+ (*mapf == 'S') * 90 + (*mapf == 'W') * 180 \
				+ (*mapf == 'N') * 270);
			}
			x++;
			mapf++;
		}
		if (*mapf)
			mapf++;
		y++;
	}
	return ;
}
