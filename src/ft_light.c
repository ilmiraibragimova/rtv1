#include "rtv1.h"

void ft_light(char **box,t_rt *r)
{
	int i;
	i = -1;

	t_light *begin;
	if (r->light == NULL) {
		r->light = (t_light *) malloc(sizeof(t_light));
		r->light->type = ft_strdup(box[1]);
		r->light->intensity = ((double) ft_atoi(box[2])) / 100;
		r->light->position.x = ft_atoi(box[3]);
		r->light->position.y = ft_atoi(box[4]);
		r->light->position.z = ft_atoi(box[5]);
		r->light->direction.x = ft_atoi(box[6]);
		r->light->direction.y = ft_atoi(box[7]);
		r->light->direction.z = ft_atoi(box[8]);
		r->light->next = NULL;
	}
	else {
		begin = r->light;
		r->light = (t_light *)malloc(sizeof(t_light));
		r->light->next = begin;
		r->light->type = ft_strdup(box[1]);
		r->light->intensity = ((double) ft_atoi(box[2])) / 100;
		r->light->position.x = ft_atoi(box[3]);
		r->light->position.y = ft_atoi(box[4]);
		r->light->position.z = ft_atoi(box[5]);
		r->light->direction.x = ft_atoi(box[6]);
		r->light->direction.y = ft_atoi(box[7]);
		r->light->direction.z = ft_atoi(box[8]);
	}

	//ft_clear_box(box, 9);
}

int		ft_shadow(t_rt *r, t_vec p, t_vec pos,  double t_min ,double t_max)
 {
	int i;
	double max_t;
	double t;
	t_vec dir;
	t_vec tmp;

	i = -1;
	t = 0;
	tmp = pos;
	tmp = vec_sub(tmp, p);
	max_t = vec_len(tmp);
	dir = vec_norm(tmp);
	p = vec_sum(p, vec_scale(dir, 0.000001));
	while (++i < r->amount_obj) {
		if (ft_strequ(r->obj[i].name, "sphere"))
			t = ray_sphere(dir, p, r->obj[i]);
		else if (ft_strequ(r->obj[i].name, "plane"))
		{//printf("TY");
			t = ft_ray_plane(dir, p, r->obj[i]);}
		else if (ft_strequ(r->obj[i].name, "cone"))
		{//printf("TY1");
			t = ft_ray_con(p, dir, &r->obj[i]);}
		else if (ft_strequ(r->obj[i].name, "cylinder"))
		{//printf("TY2");
			t = ft_ray_cylinder(p, dir, &r->obj[i]);}
		if (t >= t_min  && t < max_t)
			return (1);
	}
	return (0);
}

double lighting(t_rt *r, t_vec p, t_vec n, t_vec v, double s) {
	double i = 0.0;
	t_vec l;
	double nl;
	t_light *tmp;
	tmp = r->light;
	double t_max;
	while (tmp != NULL) {
		if (ft_strequ(tmp->type, "ambient"))
		i += tmp->intensity;
		else {
			if (ft_strequ(tmp->type, "point"))
			{
				l = vec_sub(tmp->position, p);
				t_max = 1;
			}
			else{
				l = tmp->direction;
				t_max = INFINITY;
			}
			if (ft_shadow(r, p, tmp->position, 0.00001, t_max) == 0)
			//if (r->shadow == -1)
			{
				//printf("SH");
				nl = vec_dot(n, l);
				//printf("nl%f\n", nl);
				if (nl > 0)
					//printf("SH");
					i += (tmp->intensity * nl / (vec_len(n) * vec_len(l)));
				if (s != -1)
				{
					t_vec r1 = vec_sub(vec_scale(n, (2 * vec_dot(n, l))), l);
					double r_dot_v = vec_dot(r1, v);
					if (r_dot_v > 0)
						i += tmp->intensity * pow(r_dot_v / (vec_len(r1) * vec_len(v)), s);
				}
			}
			//else
			//printf("SH");

		}
		tmp = tmp->next;
	}
	//printf("i=%f\n",i);
	if (i > 1)
	i = 1;
	return (i);

}

double *ft_lighting1(t_rt *r, t_vec vew) {
	double s[3];
	t_vec n;

	//s = (double *)malloc(sizeof(double) * 3);

	t_vec p = vec_sum(r->cam.beg, vec_scale(vew, r->closest_t));  // вычисление пересечения
	if (ft_strequ(r->obj[r->clos].name, "sphere"))
		n = ft_norm_sphere(p, r);
	else if (ft_strequ(r->obj[r->clos].name, "plane"))
		n = ft_norm_plane(vew, p, r);
	else if (ft_strequ(r->obj[r->clos].name, "cone"))
		n = ft_norm_con(vew, p, r);
	else if (ft_strequ(r->obj[r->clos].name, "cylinder"))
		n = ft_norm_cylinder(vew, p, r);
		//printf("TY");
	s[0] = r->obj[r->clos].color[0] * lighting(r, p, n, vec_scale(vew, -1), r->obj->specular);
	s[1] = r->obj[r->clos].color[1] * lighting(r, p, n, vec_scale(vew, -1), r->obj->specular);
	s[2] = r->obj[r->clos].color[2] * lighting(r, p, n, vec_scale(vew, -1), r->obj->specular);
	//printf("col0%f\n",s[0]);
	return (s);
	printf("col%f\n",r->obj->color[0]);
}