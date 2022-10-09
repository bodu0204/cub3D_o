#ifndef SETTING_H
# define SETTING_H

#define BUFFERSIZE 1024
//#include	"../../../includes/structure.h"

int setting(char *filename, t_info *i);

char	*skip_map(char *file);
int	check_map_char(char *file);
int set_map_size(char *file, size_t *x, size_t *y);
int set_map_size(char *file, size_t *x, size_t *y);
void	set_map(unsigned char	*map, char *file, size_t x);
int check_map_shape(unsigned char	*map, size_t x, size_t y);
void    set_human(t_info *i, char *mapf);
char	*read_file(char *filename);
char *reading_file(int fd, size_t B);

#endif
