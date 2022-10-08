/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:31:59 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/08 23:47:57 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

double	get_radian_from_degree(double degree)
{
	double	radian;

	if (degree < 0 || 360 <= degree)
		degree = fmod(degree, 360);
	radian = degree / 360 * 2 * M_PI;
	return (radian);
}
