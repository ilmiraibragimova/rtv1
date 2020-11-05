

#include "vec_op.h"

t_vec	vec_rot(t_vec d, t_vec r)
{
	d = vec_rotx(d, DTR(r.x));
	d = vec_roty(d, DTR(r.y));
	d = vec_rotz(d, DTR(r.z));
	return (d);
}
