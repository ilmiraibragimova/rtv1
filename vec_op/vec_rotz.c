

#include "vec_op.h"

t_vec	vec_rotz(t_vec d, double a)
{
	t_vec	r;

	r.x = d.x * cos(a) - d.y * sin(a);
	r.y = d.x * sin(a) + d.y * cos(a);
	r.z = d.z;
	return (r);
}
