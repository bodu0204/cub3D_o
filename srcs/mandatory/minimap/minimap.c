#include	"../../../includes/cub3D.h"
#include	"../../../includes/structure.h"

void	minimap(t_info *i, t_pos *p, size_t l)
{
	t_coor base;
	t_coor player;

	base_pos(&base, &player, &(i->player));
	draw_map(&base, i);
	draw_lay(&base, i, p, l);
	return 0;
}

void base_pos(t_coor *b, t_coor *p, t_pos *player)
{
	p->x = roundf(p->x * MINI_MAP_BL);
	p->y = roundf(p->y * MINI_MAP_BL);
	b->x = p->x - (MINI_MAP / 2);
	b->y = p->y - (MINI_MAP / 2);
	if (b->x < 0)
		b->x = 0.0;
	if (b->y < 0)
		b->y = 0.0;
	return ;
}

void draw_map(t_pos *b, t_info *i)
{
	
}