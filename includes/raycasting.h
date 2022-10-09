/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:23:49 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 10:00:26 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<math.h>
# include	<stdbool.h>
# include	<stdio.h>
# include	"structure.h"
# include	"map.h"

double	get_radian_from_degree(double degree);
t_pos	check_intersection(t_info *info, double angle);

#endif
