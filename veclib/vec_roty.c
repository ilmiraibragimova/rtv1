
#include "veclib.h"

t_vec	vec_roty(t_vec d, double a)
{
	t_vec r;

	r.x = d.x * cos(a) + d.z * sin(a);
	r.y = d.y;
	r.z = d.z * cos(a) - d.x * sin(a);
	return (r);
}
