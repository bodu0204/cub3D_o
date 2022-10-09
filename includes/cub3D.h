/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:45:04 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 10:56:37 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"../mlx-linux/mlx.h"
# include	"structure.h"
# include	"setting.h"
# include	"map.h"
# include	"raycasting.h"

# define BL 30
# define DIS_X 1200
# define DIS_Y 900

# define MINI_MAP 300

# define ON_KEYDOWN 2
# define ON_DESTROY 17

int	close_window(t_info *info);
int	handle_key_input(int keycode, t_info *info);

#endif
