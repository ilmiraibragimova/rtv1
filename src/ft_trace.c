#include "rtv1.h"

void ft_clear_color(double *color)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_memdel((void**)(&color[i]));
		i++;
	}
}


double closest_func(t_rt *r, t_vec vew, double t_min, double t_max, int i)
{
	double t;

	if  (ft_strequ(r->obj[i].name, "sphere"))
		t = ray_sphere( vew, r->cam.beg, r->obj[i]);
	else if (ft_strequ(r->obj[i].name, "plane")) {
		//printf("TY");
		t = ft_ray_plane(vew, r->cam.beg, r->obj[i]);
	}
	else if (ft_strequ(r->obj[i].name, "cone"))
	{
		t = ft_ray_con(r->cam.beg, vew, &r->obj[i]);
		r->obj[i].t = t;
	}
	else if (ft_strequ(r->obj[i].name, "cylinder"))
	{
		t = ft_ray_cylinder(r->cam.beg, vew, &r->obj[i]);
		r->obj[i].t = t;
	}
	if (t >= t_min && t <= t_max && t < r->closest_t)
	{
		r->closest_t = t;
		r->clos = i;
	}
	//printf("%f\n", r->closest_t);
	return (r->closest_t);
}

/*void ft_traceray1(t_rt *r, t_vec vew, t_vec l, double t_min, int t_max)
{
	int i;
	double t;
	r->shadow_t = INFINITY;
	r->shadow = -1;

	i = 0;
	//printf("am%d\n", r->amount_obj);
	while(i < r->amount_obj)
	{
		if  (ft_strequ(r->obj[i].name, "sphere"))
			t = ray_sphere(vew, l, r->obj[i]);
		else if (ft_strequ(r->obj[i].name, "plane"))
			//printf("TY");
			t = ft_ray_plane(vew, r->cam.beg, r->obj[i]);
		else if (ft_strequ(r->obj[i].name, "cone"))
			//printf("TY");
			t = ft_ray_con(l, vew, &r->obj[i]);
		//else if (ft_strequ(r->obj[i].name, "cylinder"))
			//printf("TY");
			//t = ft_ray_cylinder(l, vew, &r->obj[i]);

		if (t >= t_min && t < t_max && t < r->shadow_t)
		{
			r->shadow_t = t;
			r->shadow = i;
			//printf("s1");
		}
		//if (r->shadow != -1)
			//printf("sh%d\n",r->shadow);
		/*if (t[1] >= t_min && t[1] < t_max && t[1] < r->shadow_t)
		{
			r->shadow_t = t[1];
			r->shadow = i;
			//printf("s1");
		}
		i++;
	}
}*/

double *ft_traceray(t_vec vew, t_rt *r)
{
	r->closest_t = INFINITY;
	r->clos = -1;
	double *s;
	double s1[3] = {0, 255, 0};
	int i;

	i = 0;
	while(i < r->amount_obj)
	{
		r->closest_t = closest_func(r, vew, 1, INFINITY, i);

			//printf("s");
		i++;
	}
	if (r->clos == -1)
	{
		s = s1;
		return (s);
	}
	s = ft_lighting1(r, vew);
	//printf("%ld\n", sizeof(t_light));
	//printf("s");
	return (s);
}

t_vec ft_vewport(int i, int j, t_cam cam)
{
	t_vec t;

	t.x = (i + 0.5) / (double)WIDTH;
	t.x = 2 * t.x - 1;
	t.x = t.x * (V_W / (double)WIDTH);
	t.y = (j + 0.5) / (double)HEIGHT;
	t.y = 1 - (2 * t.y);
	t.y = t.y * (V_H / (double)HEIGHT);
	t.z = 1.0;
	t = vec_rot(t, cam.angle);
	return (t);
}

void ft_render(t_rt *r)
{
	int i;
	int j;
	double *color;
	t_vec vew;
	i = 0;

	while (i < WIDTH) {
		j = 0;
		while (j < HEIGHT) {
			vew = ft_vewport(i, j, r->cam);
			color = ft_traceray(vew, r);

			//printf("%u\n", color[0]);
			SDL_SetRenderDrawColor(r->ren, color[0], color[1], color[2], 255);
			SDL_RenderDrawPoint(r->ren, i, j);
			j++;
			//ft_clear_color(color);
		}
		i++;
	}
}
