
#include "rtv1.h"

double	ft_get_t(double k1, double k2, double k3)
{
	double	t[2];
	double	discriminant;

	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
		return (INFINITY);
	else
	{
		t[0] = (-k2 + sqrt(discriminant)) / (2 * k1);
		t[1] = (-k2 - sqrt(discriminant)) / (2 * k1);
		if ((t[0] < t[1] && t[0] > 0.0001) || (t[1] < 0 && t[0] > 0.00001))
			return (t[0]);
		else if ((t[1] < t[0] && t[1] > 0.0001) || (t[0] < 0 && t[1] > 0.00001))
			return (t[1]);
		else
			return (INFINITY);
	}
}

double	ray_sphere(t_raydata vew, t_obj obj)
{
	double	r1;
	double	k1;
	double	k2;
	double	k3;
	t_vec	oc;

	oc = vec_sub(obj.center, vew.point);
	r1 = obj.radius;
	k1 = vec_dot(vew.direction, vew.direction);
	k2 = 2.0 * vec_dot(oc, vew.direction);
	k3 = vec_dot(oc, oc) - r1 * r1;
	return (ft_get_t(k1, k2, k3));
}
