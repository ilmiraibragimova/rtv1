

#include "veclib.h"

t_vec	vec_rotx(t_vec d, double a)
{
	t_vec r;

	r.x = d.x;
	r.y = d.y * cos(a) + d.z * sin(a);
	r.z = -d.y * sin(a) + d.z * cos(a);
	return (r);
}
