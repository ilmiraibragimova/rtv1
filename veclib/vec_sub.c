
#include "veclib.h"

t_vec	vec_sub(t_vec v2, t_vec v1)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}
