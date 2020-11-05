#include "rtv1.h"

t_vec ft_norm_sphere(t_vec p, t_rt *r)
{
	t_vec n = vec_sub(p, r->obj[r->clos].center);  //# вычисление нормали сферы в точке пересечения
	n = vec_scale(n, 1 / vec_len(n));
	return (n);
}

t_vec ft_norm_plane(t_vec vew, t_vec p, t_rt *r)
{
	if (vec_dot(vew, r->obj[r->clos].end) < 0)
		return (r->obj[r->clos].end);
	return (vec_scale(r->obj[r->clos].end, -1));
}

t_vec ft_norm_con(t_vec vew, t_vec p, t_rt *r)
{
	double	m;
	t_vec	n;

	r->obj->end = vec_norm(r->obj->end);
	m = r->closest_t * vec_dot(vew, r->obj[r->clos].end) +
	    vec_dot(vec_sub(r->cam.beg, r->obj[r->clos].center), r->obj[r->clos].end);
	n = vec_scale(vec_scale(r->obj[r->clos].end, m), (1 + r->obj[r->clos].radius * r->obj[r->clos].radius));
	n = vec_norm(vec_sub(vec_sub(p, r->obj[r->clos].center), n));
	if (vec_dot(vew, n) > 0.001)
		n = vec_scale(n, -1);
	return (n);
}

t_vec ft_norm_cylinder(t_vec vew, t_vec p, t_rt *r)
{
	double	m;
	t_vec	n;

	r->obj->end = vec_norm(r->obj->end);
	m = r->closest_t * vec_dot(vew, r->obj[r->clos].end) +
	    vec_dot(vec_sub(r->cam.beg, r->obj[r->clos].center), r->obj[r->clos].end);
	n = vec_norm(vec_sub(vec_sub(p, r->obj[r->clos].center), vec_scale(r->obj[r->clos].end, m)));
	if (vec_dot(vew, n) > 0.001)
		n = vec_scale(n, -1);
	return (n);
}
