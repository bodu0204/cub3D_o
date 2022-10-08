
#ifndef CLB_3D_H
# define CLB_3D_H
# define BL 30
# define DIS_X 180
# define DIS_Y 300
typedef struct s_info
{
    
}	t_info;
typedef struct s_vector
{
    
}	t_vector;
typedef struct s_camera
{
	double	coordinate_x;
	double	coordinate_y;
	double	coordinate_z;
	double	vector_x;
	double	vector_y;
	double	vector_z;
	double	zoom;
	double	time;
	char	flag[8];
}	t_camera;
int		input_str(char *s);
int		linear_algebra(double	*algebra, double	*solution, int	x, int	y);
double	time_diff(void);
#endif
