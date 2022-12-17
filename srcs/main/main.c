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
		n.x -= sin((n.r + ra) * M_PI);
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
	if (n->r >= 2.0)
		n->r -= 2.0;
	else if(n->r < 0.0)
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
		if (n.r >= 2.0)
			n.r -= 2.0;
		else if(n.r < 0.0)
			n.r += 2.0;
		cast_line(&n, &l);
		dis_line(&l);
		n.r -= SEE / DIS_W;
		i++;
	}
	return ;
}

void cast_line(t_now *n, t_line *l)
{
	t_f fx;
	t_f fy;
	

}

int		end_cub(void	*p)
{
	img(0, 0,FERR_ALL);
	map(0, 0,FERR_ALL);
	exit(0);
}

