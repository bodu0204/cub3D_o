#include	"../../../includes/cub3D.h"
#include	"../../../includes/setting.h"
#include	"../../../libft/libft.h"

#include "debug.h"

int setting(char *filename, t_info *i)
{
	char	*file;

	file = read_file(filename);
	if (!file || map(0, 0, file) == MAP_ERROR)
		return (1);
	set_human(i, skip_map(file));
TESTd(i->player.x)
TESTd(i->player.y)
TESTd(i->direction)
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

char *reading_file(int fd, size_t B)
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

/////////////////////////////////////////////////////test
/* 
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("set arg!\n");
		return (0);
	}
	t_info i;
	if (setting(argv[1], &i))
	{
		printf("can't set!\n");
		return (0);
	}
	size_t x = 0;
	size_t y = 0;
	while (1)
	{
		x = 0;
		if (map(x, y, NULL) == MAP_ERROR)
			break;
		while (1)
		{
			int i;
			i = map(x, y, NULL);
			if (i == BLOCK)
				printf("#");
			else if (i == SPACE)
				printf(" ");
			else if (i == NONE)
				printf("+");
			else 
				break;
			x++;
		}
		printf("\n");
		y++;
	}
	return (0);
}
	
 */