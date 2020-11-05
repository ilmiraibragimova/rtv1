#include "rtv1.h"

void ft_cam(char **box, t_rt *r)
{
	int i;
	i = -1;
	r->cam.beg.x = ft_atoi(box[1]);
	r->cam.beg.y = ft_atoi(box[2]);
	r->cam.beg.z = ft_atoi(box[3]);
	r->cam.angle.x = ft_atoi(box[4]);
	r->cam.angle.y = ft_atoi(box[5]);
	r->cam.angle.z = ft_atoi(box[6]);
	ft_clear_box(box, 7);
}

