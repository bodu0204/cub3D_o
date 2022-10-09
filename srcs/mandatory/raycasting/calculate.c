/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:31:59 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 10:46:59 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

double	get_radian_from_degree(double degree)
{
	double	radian;

	if (degree < 0 || 360 <= degree)
		degree = fmod(degree, 360);
	radian = degree / 360 * 2 * M_PI;
	//printf("%f, %f\n", degree, radian);
	return (radian);
}
