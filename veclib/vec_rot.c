
#include "veclib.h"

t_vec	vec_rot(t_vec d, t_vec r)
{
	d = vec_rotx(d, r.x * M_PI / 180);
	d = vec_roty(d, r.y * M_PI / 180);
	d = vec_rotz(d, r.z * M_PI / 180);
	return (d);
}
