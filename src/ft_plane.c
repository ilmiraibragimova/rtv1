#include "rtv1.h"
void	ft_plane(t_rt *r, char **box)
{
	int i;

	i = -1;
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].end.x = (double)(ft_atoi(box[4]));
	r->obj[r->count].end.y = (double)(ft_atoi(box[5]));
	r->obj[r->count].end.z = (double)(ft_atoi(box[6]));
	//if (atoi(str[7]) < 0 || atoi(str[8]) < 0 || atoi(str[9]) < 0)
		//ft_error("Wrong input");
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[7]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[8]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[9]));
	r->obj[r->count].specular = (double)(ft_atoi(box[10]));
	r->obj[r->count].name = "plane";
	r->count++;
	ft_clear_box(box, 11);
}

/*t_vec	plane_normal(t_ray *ray, t_object *obj)
{
	if (vec_dot(ray->dir, obj->rot) < 0)
		return (obj->rot);
	return (vec_scale(obj->rot, -1));
}*/

double	ft_ray_plane(t_vec vew, t_vec cam, t_obj obj)
{
	double	t;
	double	a;
	double	b;
	t_vec	x;
	obj.end = vec_norm(obj.end);
	x = vec_sub(cam, obj.center);
	a = vec_dot(x, obj.end);
	b = vec_dot(vew, obj.end);
	//printf("IO");
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	//printf("IO");
	if (t > 0.000001){
		//printf("t%f\n",t);
		return (t);}
	return (INFINITY);
}

/*void	plane(t_rt *r, t_vec *ray, int i, t_object *obj)
{
	obj->rot = vec_norm(obj->rot);
	obj->t = plane_intersect(ray->orig, ray->dir, obj);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}*/
