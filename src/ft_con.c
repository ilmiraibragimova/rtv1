#include "rtv1.h"

void ft_con(t_rt *r, char **box) {
	int i;
	i = -1;
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].radius = (double)(ft_atoi(box[4])) / 10;
	r->obj[r->count].end.x = (double)(ft_atoi(box[5])) / 10;
	r->obj[r->count].end.y = (double)(ft_atoi(box[6])) / 10;
	r->obj[r->count].end.z = (double)(ft_atoi(box[7])) / 10;
	if (r->obj[r->count].radius < 0.1 || ft_atoi(box[5]) < 0 || ft_atoi(box[6]) < 0
	|| ft_atoi(box[7]) < 0)
		ft_put_error("Wrong input for sphere");
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[8]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[9]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[10]));
	r->obj[r->count].specular = (double)(ft_atoi(box[11]));
	r->obj[r->count].name = "cone";
	r->count++;
	ft_clear_box(box, 12);
}

double ft_ray_con(t_vec o, t_vec dir, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	t_vec	x;

	x = vec_sub(o, obj->center);
	a = vec_dot(dir, obj->end);
	a = vec_dot(dir, dir) - (1 + obj->radius * obj->radius) * a * a;
	b = 2 * (vec_dot(dir, x) - (1 + obj->radius * obj->radius) *
	                           vec_dot(dir, obj->end) * vec_dot(x, obj->end));
	c = vec_dot(x, x) - (1 + obj->radius * obj->radius) * pow(vec_dot(x, obj->end), 2);
	return (ft_get_t(a, b, c));
}


/*(t_obj obj, t_vec vew, t_vec cam)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	x;

	x = vec_sub(cam, obj.center);
	a = vec_dot(vew, obj.end);
	a = vec_dot(vew, vew) - (1 + obj.radius * obj.radius) * a * a;
	b = 2 * (vec_dot(vew, x) - (1 + obj.radius * obj.radius) *
	                           vec_dot(vew, obj.end) * vec_dot(x, obj.end));
	c = vec_dot(x, x) - (1 + obj.radius * obj.radius) * pow(vec_dot(x, obj.end), 2);
	d = b * b - 4 * a * c;
	//printf("MM");
	if (d < 0.0001)
		return (-1);
	return (ft_get_t(a, b, d));
}*/
