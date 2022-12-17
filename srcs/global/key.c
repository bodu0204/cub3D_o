#include "../cub3D.h"

unsigned 	key(unsigned set)
{
	static unsigned k;

	if (set & GO_)
	{
		k &= TRN_;
		k |= set;
	}
	if (set & TRN_)
	{
		k &= GO_;
		k |= set;
	}
	return (k);
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