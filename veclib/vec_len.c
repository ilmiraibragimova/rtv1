
#include "veclib.h"

double	vec_len(t_vec v1)
{
	return (sqrt(vec_dot(v1, v1)));
}
