
#include "rtv1.h"

double	ft_ray_plane(t_raydata ray, t_obj obj, int f)
{
	double		t;
	double		v_r;
	double		o_r;
	t_vec		x;

	x = vec_sub(obj.center, ray.point);
	o_r = vec_dot(x, obj.rot);
	v_r = vec_dot(ray.direction, obj.rot);
	t = (-o_r) / v_r;
	if (f == 1)
		return (t);
	//printf ("%f\n", t);
	if ((t > 0.0001 && t < ray.t_max))
		return (t);
	return (INFINITY);
}
