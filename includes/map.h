/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:25:48 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 14:47:27 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"structure.h"

unsigned char *mk_map(char *file, size_t *x, size_t *y);

#endif
