/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:37:57 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 22:17:34 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# define BUFFERSIZE 1024

# include	"../libft/libft.h"
# include	"cub3D.h"
# include	"global.h"

int				setting(char *filename, t_info *i);
char			*skip_map(char *file);
int				check_map_char(char *file);
int				set_map_size(char *file, size_t *x, size_t *y);
int				set_map_size(char *file, size_t *x, size_t *y);
void			set_map(unsigned char	*map, char *file, size_t x);
int				check_map_shape(unsigned char	*map, size_t x, size_t y);
void			set_human(t_info *i, char *mapf);
char			*read_file(char *filename);
char			*reading_file(int fd, size_t B);
unsigned char	*mk_map(char *file, size_t *x, size_t *y);
unsigned int	get_pic(t_img *img, size_t x, size_t y);

int				set_imgs(char *file, t_info *i);
int				set_img_fname(char *img_n[], char *file);
size_t			set_img_elm(char *img_n[], char *file);
size_t			set_fc_elm(char *file, unsigned int *f);
unsigned int	str_to_rgb(char * str, unsigned int *f);
int				set_imgf(char *img_n[], void *img_f[], t_info *i);
void			rm_imgs(void *img_f[], t_info *i);
char			*is_xpm(char *f);
void			restore_file(char *fname[]);
int				mk_img(void *img, unsigned int *dst);

#endif
