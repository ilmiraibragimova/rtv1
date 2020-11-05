#include "rtv1.h"
void ft_cylinder(t_rt *r, char **box) {
	int i;
	i = -1;
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].radius = (double)(ft_atoi(box[4])) / 10;
	r->obj[r->count].end.x = (double)(ft_atoi(box[5]));
	r->obj[r->count].end.y = (double)(ft_atoi(box[6]));
	r->obj[r->count].end.z = (double)(ft_atoi(box[7]));
	//if (r->obj[r->count].radius < 0.1 || ft_atoi(box[5]) < 0 || ft_atoi(box[6]) < 0
	//|| ft_atoi(box[7]) < 0)
	//write(1, "Wrong input for sphere", 20);
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[8]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[9]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[10]));
	r->obj[r->count].specular = (double)(ft_atoi(box[11]));
	r->obj[r->count].name = "cylinder";
	r->count++;
	//printf("CYL");
	//ft_clear_box(box, 12);
}

double	ft_ray_cylinder(t_vec o, t_vec dir, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	x;

	x = vec_sub(o, obj->center);
	a = vec_dot(dir, dir) - pow(vec_dot(dir, obj->end), 2);
	b = 2 * (vec_dot(dir, x) - (vec_dot(dir, obj->end) * vec_dot(x, obj->end)));
	c = vec_dot(x, x) - pow(vec_dot(x, obj->end), 2) - pow(obj->radius, 2);
	//d = b * b - 4 * a * c;
	//if (d < 0)
		//return (-1);
	//printf("co");
	return (ft_get_t(a, b, c));
}
