#include "../cub3d.h"

int set_head(char *file);
int set_map(char *file);

int	main(int argc, char *argv[])
{
	void	*buf;

	if (argc != 2)
		return(printf("Error\n") * 0 + 1);
	mlx(mlx_init());
	win(mlx_new_window(mlx(0), DIS_W, DIS_H, "cub3d"));
	if (set_head(argv[1]) || set_map(argv[1]))
		return (1);
	mlx_loop_hook(mlx(0), cub3d, NULL);
	mlx_hook(win(0), 2, 0, set_key, NULL);
	mlx_hook(win(0), 3, 0, rm_key, NULL);
	mlx_hook(win(0), 17, 0, end_cub, NULL);
	mlx_loop(mlx(0));
	return (0);
}

char *read_file(int fd, size_t B);
int img_mame(char **dst , char *file);
int set_img(char **name, unsigned *imgs);
int set_cf(char **str);

int set_head(char *file)
{
	int fd;
	char *name[7];
	unsigned imgs[BL * BL * 4];

	fd = open(file, O_RDONLY);
	file = read_file(fd, 0);
	close(fd);
	ft_bzero(name, sizeof(name));
	if (img_mame(name, file) || set_img(name, imgs) || set_cf(name))
		return (1);
	free(file);
	return (0);
}


char *read_file(int fd, size_t B)
{
	ssize_t l;
	char s[BUFER_SIZE];
	char *r;

	l = read(fd, s, B);
	if (l < 0)
		return (NULL);
	else if (l == 0)
	{
		r = malloc(B + 1);
		if (r)
			r[B] = '\0';
		return (r);
	}
	r = read_file(fd, B + l);
	if (r)
		ft_memcpy(r + B, s, l);
	return (r);	
}

int switch_name(char **dst, char *file, unsigned *f);

int img_mame(char **dst , char *file)
{	
	unsigned f;

	f = 0;
	while (*file)
	{
		while (*file && *file == ' ')
			file++;
		if (switch_name(dst, file, &f))
			break;
		while (*file && *file != '\n')
			file++;
		if (*file == '\n')
		{
			*file = '\0';
			file++;
		}
	}
	if (f != 0b111111)
		return (1);
	while (*dst)
	{
		while (**dst == ' ')
			(*dst)++;
		dst++;
	}
	return (0);
}

int switch_name1(char **dst, char *file, unsigned *f);
int switch_name2(char **dst, char *file, unsigned *f);

int switch_name(char **dst, char *file, unsigned *f)
{
	if (!ft_memcmp(file, "NO", 2))
	{
		if (*f & 1U << NORTH)
		{
			*f ^= 1U << NORTH;
			return (1);
		}
		*f |= 1U << NORTH;
		dst[NORTH] = file + 2;
	}
	else if (!ft_memcmp(file, "EA", 2))
	{
		if (*f & 1U << EAST)
		{
			*f ^= 1U << EAST;
			return (1);
		}
		*f |= 1U << EAST;
		dst[EAST] = file + 2;
	}
	else
		return (switch_name1(dst, file, f));
	return (0);
}


int switch_name1(char **dst, char *file, unsigned *f)
{
	if (!ft_memcmp(file, "SO", 2))
	{
		if (*f & 1U << SOUTH)
		{
			*f ^= 1U << SOUTH;
			return (1);
		}
		*f |= 1U << SOUTH;
		dst[SOUTH] = file + 2;
	}
	else if (!ft_memcmp(file, "WE", 2))
	{
		if (*f & 1U << WEST)
		{
			*f ^= 1U << WEST;
			return (1);
		}
		*f |= 1U << WEST;
		dst[WEST] = file + 2;
	}
	else
		return (switch_name2(dst, file, f));
	return (0);
}

int switch_name2(char **dst, char *file, unsigned *f)
{
	if (*file == 'C')
	{
		if (*f & 1U << 4)
		{
			*f ^= 1U << 4;
			return (1);
		}
		*f |= 1U << 4;
		dst[4] = file + 1;
	}
	else if (*file == 'F')
	{
		if (*f & 1U << 5)
		{
			*f ^= 1U << 5;
			return (1);
		}
		*f |= 1U << 5;
		dst[5] = file + 1;
	}
	else if (*file == '\n' || !(*file))
		return (0);
	return (1);
}

void set_img_bit(unsigned *p, int bits_per_pixel, int size_line, unsigned *dst);
int set_img(char **name, unsigned *imgs)
{
	size_t	i;
	int	bp;
	int	sl;
	int buf;
	void *img_data;

	i = 0;
	while (i < 4)
	{
		img_data = mlx_xpm_file_to_image(mlx(0), name[i], &bp, &sl);
		if (!img_data || bp < BL || sl < BL)
			return (1);
		set_img_bit((unsigned *) mlx_get_data_addr(img_data, &bp, &sl, &buf), \
		sl, bp , imgs + (BL * BL * i));
		mlx_destroy_image(mlx(0), img_data);
		i++;
	}
	img(SET, 0, imgs);
	return (0);
}

void set_img_bit(unsigned *p, int bits_per_pixel, int size_line, unsigned *dst)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < BL)
	{
		x = 0;
		while(x < BL)
		{
			dst[x * BL + y] = p[y * size_line + x * (bits_per_pixel / 8)];
			x++;
		}
		y++;
	}
	return ;
}


void	set_cf1(size_t	i, unsigned n);

int set_cf(char **str)
{
	size_t i;
	size_t ii;
	size_t l;
	unsigned n;
	
	i = 4;
	while (i < 6)
	{
		ii = 0;
		n = 0;
		while (ii < 3)
		{
			l = 0;
			while (ft_isdigit(str[i][l]))
				l++;
			if (l == 0 || l > 3 || ft_atoi(str[i]) > 0xff || \
			(ii < 2 && str[i][l] != ',') || (ii == 2 && str[i][l] != '\0'))
				return (1);
			n |= ft_atoi(str[i]) << (3 - ii) * 8;
			str[i] += l + 1;
			ii++;
		}
		set_cf1(i, n);
		i++;
	}
	return (0);
}

void	set_cf1(size_t	i, unsigned n)
{
	if (i == 4)
		ceiling(n);
	else
		flooring(n);
}

int		cub3d(void	*p)
{
	move();
	cast();
	return (0);
}



void move1(t_now *n);

void move()
{
	double ra;
	t_now n;

	n = now(0);
	if ((key(0) & GO_) == GO_F)
		ra = 0;
	else if ((key(0) & GO_) == GO_L)
		ra = 0.5;
	else if ((key(0) & GO_) == GO_B) 
		ra = 1;
	else if ((key(0) & GO_) == GO_R) 
		ra = 1.5;
	if ((key(0) & GO_) != GO_NONE)
	{
		n.x += sin((n.r + ra) * M_PI);
		n.y += cos((n.r + ra) * M_PI);
	}
	move1(&n);
}

void move1(t_now *n)
{
	if ((key(0) & TRN_) == TRN_L)
		n->r += TRN_LEN;
	else if ((key(0) & TRN_) == TRN_R)
		n->r -= TRN_LEN;
	while (n->r >= 2.0)
		n->r -= 2.0;
	while (n->r < 0.0)
		n->r += 2.0;
	*n = now(n);
}

void cast_line(t_now *n, t_line *l);

void	dis_line1(t_line *l, size_t i);
void	dis_line(t_line *l, size_t i)
{
	double y;
	double pic_l;
	int	d;

	pic_l = l->far * sqrt(3) / 2;
	d = DIS_H / 2 - 1;
	y = BL / 2 - MINI_NUM;
	while (d >= 0)
	{
		if (y >= 0)
		{
			y -= pic_l;
			dis(i, d, l->data[(int)floor(y)], CLOR);
		}
		else
			dis(i, d, ceiling(0), CLOR);
		d--;
	}
	dis_line1(l, i);
}

void	dis_line1(t_line *l, size_t i)
{
	double y;
	double pic_l;
	int	d;

	pic_l = l->far * sqrt(3) / 2;
	d = DIS_H / 2;
	y = BL / 2;
	while (d < DIS_H)
	{
		if (y < BL)
		{
			dis(i, d, l->data[(int)floor(y)], CLOR);
			y += pic_l;
		}
		else
			dis(i, d, ceiling(0), CLOR);
		d++;
	}
}


void cast()
{
	size_t i;
	t_now n;
	t_line	l;

	n = now(0);
	n.r += SEE / 2;
	if (n.r)
	while (i < DIS_W)
	{
		while (n.r >= 2.0)
			n.r -= 2.0;
		while (n.r < 0.0)
			n.r += 2.0;
		cast_line(&n, &l);
		l.far *= sin((now(0).r - n.r) * M_PI);
		dis_line(&l, i);
		n.r -= SEE / DIS_W;
		i++;
	}
	dis(0, 0, 0, FLUSH);
	return ;
}

void cast_line_init(double r, t_f *fx, t_f *fy);
void cast_line1(t_line *l, t_f *fx, t_f *fy);
void cast_line2(t_line *l, t_f *fx, t_f *fy);
void cast_line3(t_line *l, t_f *fx, t_f *fy);
void cast_line4(t_line *l, t_f *fx, t_f *fy);
void cast_line_retE(double rx, double ry, t_line *l);
void cast_line_retN(double rx, double ry, t_line *l);
void cast_line_retW(double rx, double ry, t_line *l);
void cast_line_retS(double rx, double ry, t_line *l);

void cast_line(t_now *n, t_line *l)
{
	t_f fx;
	t_f fy;
	
	cast_line_init(n->r, &fx, &fy);
	if (n->r < 0.5)
		cast_line1(l, &fx, &fy);
	else if (n->r < 1.0)
		cast_line2(l, &fx, &fy);
	else if (n->r < 1.5)
		cast_line3(l, &fx, &fy);
	else //(n->r < 2.0)
		cast_line4(l, &fx, &fy);
}

void cast_line_init(double r, t_f *fx, t_f *fy)
{
	fx->a = tan(r * M_PI);
	fx->b =  now(0).y - tan(r * M_PI) * now(0).x;
	fy->a = 1.0 / tan(r * M_PI);
	fy->b = now(0).x - now(0).y / tan(r * M_PI);
}



void cast_line1(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

	x = floor(now(0).x) + 1.0;
	y = floor(now(0).y) + 1.0;
	while (map(x, y, 0) != BLOCK)
	{
		f = 1;
		ry = fx->a * x + fx->b;
		if (ry > y)
		{
			f = 0;
			rx = fy->a * y + fy->b;
			y++;
		}
		else
			x++;
	}
	if (f)
		cast_line_retE(x, ry, l);
	else
		cast_line_retS(rx, y, l);
	return;

}

void cast_line2(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

	x = floor(now(0).x);
	y = floor(now(0).y) + 1.0;
	while (map(x, y, 0) != BLOCK)
	{
		f = 1;
		ry = fx->a * x + fx->b;
		if (ry > y)
		{
			f = 0;
			rx = fy->a * y + fy->b;
			y++;
		}
		else
			x--;
	}
	if (f)
		cast_line_retW(x, ry, l);
	else
		cast_line_retS(rx, y, l);
	return;

}

void cast_line3(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

	x = floor(now(0).x);
	y = floor(now(0).y);
	while (map(x, y, 0) != BLOCK)
	{
		f = 1;
		ry = fx->a * x + fx->b;
		if (ry > y)
		{
			f = 0;
			rx = fy->a * y + fy->b;
			y--;
		}
		else
			x--;
	}
	if (f)
		cast_line_retW(x, ry, l);
	else
		cast_line_retN(rx, y, l);
	return;

}

void cast_line4(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

	x = floor(now(0).x) + 1.0;
	y = floor(now(0).y);
	while (map(x, y, 0) != BLOCK)
	{
		f = 1;
		ry = fx->a * x + fx->b;
		if (ry > y)
		{
			f = 0;
			rx = fy->a * y + fy->b;
			y--;
		}
		else
			x++;
	}
	if (f)
		cast_line_retS(x, ry, l);
	else
		cast_line_retN(rx, y, l);
	return;

}

void cast_line_retW(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(WEST, round((floor(ry) + 1 - ry) * BL), l->data);
}

void cast_line_retN(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(NORTH, round((rx - floor(rx)) * BL), l->data);
}

void cast_line_retE(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(EAST, round((ry - floor(ry)) * BL), l->data);
}

void cast_line_retS(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(SOUTH, round((floor(rx) + 1 - rx) * BL), l->data);
}


int	set_key(int	k, void	*p)
{
	unsigned i;

	(void)p;
	if (k == W_KEY)
		key(GO_F);
	else if (k == S_KEY)
		key(GO_B);
	else if (k == A_KEY)
		key(GO_L);
	else if (k == D_KEY)
		key(GO_R);
	else if (k == TL_KEY)
		key(TRN_L);
	else if (k == TR_KEY)
		key(TRN_R);
	else if (k == ESC_KEY)
		end_cub(NULL);
	return (0);
}


int	rm_key(int	k, void	*p)
{
	if (k == W_KEY || k == S_KEY || k == A_KEY || k == D_KEY)
		key(GO_NONE);
	else if (k == TL_KEY || k == TR_KEY)
		key(TRN_NONE);
	return (0);
}


int		end_cub(void	*p)
{
	img(0, 0, (unsigned int *) FREE_ALL);
	dis(0, 0, 0, (int) FREE_ALL);
	exit(0);
}

