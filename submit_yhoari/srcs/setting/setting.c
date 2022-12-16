/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:36 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/11 19:13:29 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setting.h"

int	setting(char *filename, t_info *i)
{
	char	*file;

	if (ft_memcmp(filename + ft_strlen(filename) - 4, ".cub", 4))
		return (1);
	file = read_file(filename);
	if (!file || set_imgs(file, i) || map(0, 0, file) == MAP_ERROR)
		return (1);
	set_human(i, skip_map(file));
	free(file);
	return (0);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*r;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	r = reading_file(fd, 0);
	close(fd);
	return (r);
}

char	*reading_file(int fd, size_t B)
{
	char	buf[BUFFERSIZE];
	ssize_t	i;
	char	*r;

	i = read(fd, buf, BUFFERSIZE);
	if (i < 0)
		return (NULL);
	else if (i == 0)
	{
		r = malloc(B + 1);
		r[B] = '\0';
	}
	else
		r = reading_file(fd, B + i);
	if (r)
		ft_memcpy(r + B, buf, i);
	return (r);
}
