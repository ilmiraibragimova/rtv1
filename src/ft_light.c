#include "rtv1.h"

int		ft_shadow(t_rt *r, t_vec p, t_vecs pos)
{
	int			i;
	t_raydata	ray;

	i = 0;
	r->shadow_t = 0;
	ray = creat_ray(pos.t_max, p, vec_norm(pos.l));
	while (i < r->amount_obj && r->amount_obj != 1)
	{
		if (ft_strequ(r->obj[i].name, "sphere"))
			r->shadow_t = ray_sphere(ray, r->obj[i]);
		else if (ft_strequ(r->obj[i].name, "plane"))
			r->shadow_t = ft_ray_plane(ray, r->obj[i]);
		else if (ft_strequ(r->obj[i].name, "cone"))
			r->shadow_t = ft_ray_con(ray, &r->obj[i]);
		else if (ft_strequ(r->obj[i].name, "cylinder"))
			r->shadow_t = ft_ray_cylinder(ray, &r->obj[i]);
		if (r->shadow_t > 0.00001 && r->shadow_t < pos.t_max)
			return (1);
		i++;
	}
	return (0);
}

void	ft_lighting2(t_rt *r, t_light *tmp, t_vec l, t_raydata ray)
{
	t_vec	r1;
	double	r_dot_v;
	double	nl;
	t_vec	n;

	n = r->obj[r->clos].n;
	nl = vec_dot(n, l);
	if (((nl > 0) && (vec_dot(r->obj[r->clos].n, ray.direction) < 0))\
		|| (nl < 0 && (vec_dot(r->obj[r->clos].n, ray.direction) > 0) \
		&& bord(r, tmp)))
	{
		if (nl < 0)
			nl = -nl;
		r->intensity += (tmp->intensity * nl / (vec_len(n) * vec_len(l)));
	}
	if (r->obj[r->clos].specular != -1)
	{
		r1 = vec_sub(l, vec_scale(n, (2 * vec_dot(n, l))));
		r_dot_v = vec_dot(r1, vec_scale(ray.direction, -1));
		if (r_dot_v > 0 && nl > 0)
			r->intensity += tmp->intensity * pow(r_dot_v /
					(vec_len(r1) * vec_len(vec_scale(ray.direction, -1))),\
					r->obj[r->clos].specular);
	}
}

t_vecs	ft_lighting3(t_light *tmp, t_vecs vecs, t_vec p)
{
	if (ft_strequ(tmp->type, "point"))
	{
		vecs.l = vec_sub(p, tmp->position);
		vecs.t_max = vec_len(vecs.l);
		vecs.k = tmp->position;
	}
	else
	{
		vecs.l = vec_norm(tmp->direction);
		vecs.t_max = INFINITY;
		vecs.k = tmp->direction;
	}
	return (vecs);
}

double	lighting(t_rt *r, t_vec p, t_raydata vew)
{
	t_vecs	vecs;
	t_light	*tmp;

	r->intensity = 0.0;
	tmp = r->light;
	while (tmp != NULL)
	{
		if (ft_strequ(tmp->type, "ambient"))
			r->intensity += tmp->intensity;
		else
		{
			vecs = ft_lighting3(tmp, vecs, p);
			if (ft_shadow(r, p, vecs) == 0)
				ft_lighting2(r, tmp, vecs.l, vew);
		}
		tmp = tmp->next;
	}
	if (r->intensity > 1)
		r->intensity = 1;
	return (r->intensity);
}

t_vec	ft_lighting1(t_rt *r, t_raydata vew)
{
	t_vec	s;
	t_vec	p;

	p = vec_sum(r->cam.point, vec_scale(r->cam.direct, r->closest_t));
	if (ft_strequ(r->obj[r->clos].name, "sphere"))
		r->obj[r->clos].n = ft_norm_sphere(p, r);
	else if (ft_strequ(r->obj[r->clos].name, "plane"))
		r->obj[r->clos].n = ft_norm_plane(r);
	else if (ft_strequ(r->obj[r->clos].name, "cone"))
		r->obj[r->clos].n = ft_norm_con(vew.direction, p, r);
	else if (ft_strequ(r->obj[r->clos].name, "cylinder"))
		r->obj[r->clos].n = ft_norm_cylinder(vew.direction, p, r);
	s.x = r->obj[r->clos].color[0] * lighting(r, p, vew);
	s.y = r->obj[r->clos].color[1] * lighting(r, p, vew);
	s.z = r->obj[r->clos].color[2] * lighting(r, p, vew);
	return (s);
}
