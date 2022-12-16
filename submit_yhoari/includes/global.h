/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:25:48 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 22:17:43 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"../libft/libft.h"
# include	"structure.h"
# include	"cub3D.h"
# include	"setting.h"

# define BITS_PER_PIXEL 0
# define SIZE_LINE 1
# define ENDIAN 2

int				map(size_t x, size_t y, char *file);
int				img(unsigned int *dest, t_direction d, size_t col, void *img_data);
unsigned int	flooring(unsigned int set);
unsigned int	ceiling(unsigned int set);

#endif
