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
