
#include "veclib.h"

t_vec	vec_norm(t_vec v1)
{
	double inv;

	inv = 1 / vec_len(v1);
	return (vec_scale(v1, inv));
}
