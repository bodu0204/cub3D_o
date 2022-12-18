#include "../cub3d.h"


int	main(int argc, char *argv[])
{
	void	*buf;

	if (argc != 2)
		return(printf("Error\n") * 0 + 1);
	mlx(mlx_init());
	win(mlx_new_window(mlx(0), DIS_W, DIS_H, "cub3d"));
	if (setting(argv[1]))
		return (1);
	mlx_loop_hook(mlx(0), cub3d, NULL);
	mlx_hook(win(0), 2, 0, set_key, NULL);
	mlx_hook(win(0), 3, 0, rm_key, NULL);
	mlx_hook(win(0), 17, 0, end_cub, NULL);
	mlx_loop(mlx(0));
	return (0);
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
	if (key(0) & GO_ == GO_F)
		ra = 0;
	else if (key(0) & GO_ == GO_L)
		ra = 0.5;
	else if (key(0) & GO_ == GO_B) 
		ra = 1;
	else if (key(0) & GO_ == GO_R) 
		ra = 1.5;
	if (key(0) & GO_ != GO_NONE)
	{
		n.x += sin((n.r + ra) * M_PI);
		n.y += cos((n.r + ra) * M_PI);
	}
	move1(&n);
}

void move1(t_now *n)
{
	if (key(0) & TRN_ == TRN_L)
		n->r += TRN_LEN;
	else if (key(0) & TRN_ == TRN_R)
		n->r -= TRN_LEN;
	while (n->r >= 2.0)
		n->r -= 2.0;
	while (n->r < 0.0)
		n->r += 2.0;
	*n = now(n);
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
		dis_line(&l, i);
		n.r -= SEE / DIS_W;
		i++;
	}
	//dis();
	return ;
}

void cast_line_init(double r, t_f *fx, t_f *fy);
void cast_line_1(t_line *l, t_f *fx, t_f *fy);
void cast_line_2(t_line *l, t_f *fx, t_f *fy);
void cast_line_3(t_line *l, t_f *fx, t_f *fy);
void cast_line_4(t_line *l, t_f *fx, t_f *fy);
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



void cast_line_1(t_line *l, t_f *fx, t_f *fy)
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

void cast_line_2(t_line *l, t_f *fx, t_f *fy)
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
			x++;
	}
	if (f)
		cast_line_retW(x, ry, l);
	else
		cast_line_retS(rx, y, l);
	return;

}

void cast_line_3(t_line *l, t_f *fx, t_f *fy)
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
			y++;
		}
		else
			x++;
	}
	if (f)
		cast_line_retW(x, ry, l);
	else
		cast_line_retN(rx, y, l);
	return;

}

void cast_line_4(t_line *l, t_f *fx, t_f *fy)
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
			y++;
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
	img(WEST, round((floor(ry) + 1 - ry) * BL), &(l->data));
}

void cast_line_retN(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(NORTH, round((rx - floor(rx)) * BL), &(l->data));
}

void cast_line_retE(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(EAST, round((ry - floor(ry)) * BL), &(l->data));
}

void cast_line_retS(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(SOUTH, round((floor(rx) + 1 - rx) * BL), &(l->data));
}

int		end_cub(void	*p)
{
	img(0, 0,FERR_ALL);
	map(0, 0,FERR_ALL);
	exit(0);
}

